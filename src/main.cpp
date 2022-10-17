#include <Arduino.h>

class DevBoard
{
  private:
    int ram;
  public:
    int flash;
    DevBoard(){
      this->flash=1024;
      this->ram=256;
      this->cpuCore =1 ;
    };
  protected:
    int cpuCore;
  
};

class Esp32Board : public DevBoard{
  public:
    int getCpuCore(){return cpuCore;}
  private:
  protected:
};

class Esp32Board_private : private DevBoard{
  public:
    int getCpuCore(){return cpuCore;}
    int getFlash(){return flash;}
  private:
  protected:
};

class Esp32Board_protected : protected DevBoard{
  public:
    int getCpuCore(){return cpuCore;}
    int getFlash(){return flash;}
  private:
  protected:
};

class Esp32C3 : public Esp32Board_protected{
  public:
    int getCpuCore(){return cpuCore;}
    int getFlash(){return flash;}
  private:
  protected:
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  DevBoard devboard;
  Esp32Board esp32Board;
  Esp32Board_private esp32Board_1;
  Esp32C3 esp32Board_2;

  Serial.println("    Public inheritance");
  Serial.print("This's a Public information of sub class : ");
  Serial.println(esp32Board.flash);
  Serial.print("This's a Portected information of Parent class : ");
  Serial.println(esp32Board.getCpuCore());

  Serial.println("    Private inheritance");
  Serial.print("This's a Public information of sub class : ");
  Serial.println(esp32Board_1.getFlash());
  Serial.print("This's a Portected information of Parent class : ");
  Serial.println(esp32Board_1.getCpuCore());

  Serial.println("    Protected inheritance");
  Serial.print("This's a Public information of sub class : ");
  Serial.println(esp32Board_2.getFlash());
  Serial.print("This's a Portected information of Parent class : ");
  Serial.println(esp32Board_2.getCpuCore());
}

void loop() {
  // put your main code here, to run repeatedly:
}