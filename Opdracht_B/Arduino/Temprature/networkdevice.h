// TODO: make easy inhert class for use
// TODO: document easy inhert class (extra: write pdf documentation?)


#ifndef NETWORKDEVICE
#define NETWORKDEVICE

#include <Ethernet.h>
#include <SPI.h>

#include <HashMap.h>

EthernetClient client;

class Command;
const byte HASH_SIZE = 100;
HashType<String*, Command*>FunctionCommands[HASH_SIZE];
HashMap<String*, Command*> hashMap = HashMap<String*, Command*>(FunctionCommands, HASH_SIZE);

class Command
{
  public:
    Command(String _id, void* com, String typeString) // TODO: add id
    {
      pointer = com;
      types = typeString;
      id = _id;
    }
    String id;
    void* pointer;
    String types;
};

class NetworkDevice
{
  public:
    byte mac[6] = {0xA8, 0x61, 0x0A, 0xAE, 0x01, 0x45};
    byte server[4] = { 192, 168, 1, 3 };
    byte ip[4] = { 192, 168, 1, 100 };
    bool Init(String authKey, String name, String description)
    {
      // put your setup code here, to run once:
      Serial.println("Initialize Ethernet with DHCP:");
      if (Ethernet.begin(mac) == 0) {
        Serial.println("Failed to configure Ethernet using DHCP");
        return false;
      }
      Serial.print("My IP address: ");
      Serial.println(Ethernet.localIP());
      Serial.println("Starting Connection");
      if (client.connect(server, 11000))
      {
        Serial.println("Connected");
        SendMessageToServer("AUTHDEV;" + authKey + ";" + name + ";" + description);
        int cs = client.available();
        while (cs == 0)
        {
          delay(1);
          cs = client.available();
        }
        for (int i = 0; i < commandAmount; i++)
        {
          SendRegisterCommand((*hashMap[i].getHash()), hashMap[i].getValue());
        }
        SendMessageToServer("COMPLETE"); // TODO: tell server that device is done with init
      }
      else
      {
        return false;
      }
      return true;
    }

    //INT=0,FLOAT=1,BOOL=2,STRING=3
    void RegisterCommand(String id, String name, void* command, String types) // add id
    {
      Command* com = new Command(id, command, types);
      String *h = new String(name);
      hashMap[commandAmount](h, com);
      commandAmount++;
      // SendRegisterCommand(name, com);
    }

    void SendMessageToServer(String str) {
      if (client.connected())
      {
        Serial.println(str);
        client.println(str);
      }
    }

    void HandleCommand()
    {
      if (client.connected())
      {
        String command = "";
        int cs = client.available();
        if (cs == 0)
          return;
        while (cs)
        {
          char c = (char)client.read();
          command += c;
          cs--;
        }
        Serial.println(command);
        String subCommand = command.substring(0, 3);
        if (subCommand == "RET")
        {
          String CommandString = command.substring(4);
          String id = CommandString.substring(0, CommandString.lastIndexOf(';'));
          for (int i = 0; i < commandAmount; i++)
          {
            if(*hashMap[i].getHash() == id){
              Serial.println("im in: " + String(id));
              void (*f)() = hashMap[i].getValue()->pointer;
              f();
              return;
            }
          }
        }
        else if (subCommand == "COM")
        {

          String CommandString = command.substring(4);
          String id = CommandString.substring(0, CommandString.lastIndexOf(';'));
          for (int i = 0; i < commandAmount; i++)
          {
            if(*hashMap[i].getHash() == id){
              Serial.println("im in: " + String(id));
              void (*f)() = hashMap[i].getValue()->pointer;
              f();
              return;
            }
          }
        }
        else {
          Serial.println("NO FITTING COMMAND");
        }
      }
    }
  private:
    int commandAmount = 0;
    void SendRegisterCommand(String Name, Command* command)
    {
      SendMessageToServer(command->id + ";" + Name + ";" + command->types);
    }

};

#endif
