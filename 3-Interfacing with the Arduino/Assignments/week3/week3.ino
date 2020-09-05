#include <EEPROM.h>

String input_data;
void setup()
{
  Serial.begin(9600);
  Serial.println("If you want to read data then type read <write address here> eg. read 8");
  Serial.println("If you want to write then type write <address data_in_integers> eg write 5 10");
}

void loop()
{
  
  if (Serial.available()>0)
  {
    input_data = Serial.readStringUntil('\n'); 
    String dataRead = input_data;
    String dataWrite = input_data;
    String serial_Read = "read";
    String serial_Write = "write";
    dataRead.remove(4);//Modify in place a String removing chars from the provided index to the end of the String
    dataWrite.remove(5);
    
    if (dataRead.equals(serial_Read)) 
    {
      String read_add = input_data.substring(5);// substring(the index to start the substring at)
      
      int real_add = read_add.toInt();// convert the substring to integer
      
      if (real_add > 1023 || real_add < 0) //check if the address is valid
      {
        
      Serial.println("Invalid address, it should be from 1 to 1023");
      
      }

      else 
      { 
        int memRead = EEPROM.read(real_add); 
        Serial.print("Address ");
         Serial.print(read_add);
        Serial.print(" has value ");
        Serial.println(memRead, DEC);
      }
    } 
      
      if (dataWrite.equals(serial_Write)) 
      { 
      
      String write_add = input_data;
      
      write_add.remove(0, 6);
      
      int burn_add = write_add.indexOf(' ');//the value to search for - char or String
      
      String s1 = write_add.substring(0, burn_add);
      
      int write_real_add = s1.toInt(); 
      
      String s2 = write_add.substring(burn_add + 1); 
      
      int write_real_data = s2.toInt(); 

      if (write_real_add < 0 || write_real_add > 1023 || write_real_data < 0 || write_real_data > 1023) 
      {
        
        Serial.println("Invalid, enter the address and data from 0 to 1023");
        
      }

      else { 
        byte add1 = write_real_data & 0XFF;
        
        byte num2 = (write_real_data >> 8) & 0XFF;
        
        EEPROM.write(write_real_add, add1);
        
        EEPROM.write(write_real_add + 1, num2);
        
        Serial.println("Data has been wriiten ");
        
      }
     }
  }
}
