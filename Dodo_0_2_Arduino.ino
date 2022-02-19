/*定义各模拟口电压变量*/
int Vol[15]={};

/*计数器、模拟口引脚编号*/
int counter,analogPin=0;

void setup() 
{
  Serial.begin(115200);
}

void loop() 
{
  Serial.write(0xAA);
  for(counter=0;counter<15;counter++)
  {
    analogPin=counter+54;
    Vol[counter]=analogRead(analogPin);
    /*高低8位*/
    Serial.write((char)(Vol[counter]/256));
    Serial.write((char)(Vol[counter]%256));
  }
  Serial.write(0x55);
  
/*经测试，每发送1帧数据后再间隔6ms，数据刷新频率约120Hz。（发送1200帧数据用时9.7s）*/
  delay(6);
}
