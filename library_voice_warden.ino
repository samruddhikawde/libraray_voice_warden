String books[70]={"Let us C","Let us see","Programming in C","Computer Graphics by Alex","Theory of Computation","Micro computer System 8086","Data Structure using C and C plus plus","Data Structure Through C in Depth","Data Structure through C","Object Oriented Programming with C plus plus","compiler principles","compiler principle","advanced compiler design","the design of unix architecture","computer organisation and architecture","Artificial intelligence","data science"};
//String books[70]={"Let us C by Yaswant Kanetkar","Let us see by Yaswant Kanetkar","Programming in C by BL Juneja","Discrete mathematical structures with applications to computer science by JP Tremblay","Modern Digital Electronics by RP jain","Computer Graphics by Donald Hearn","Introduction to languages and theory of computation by John C Martin","Theory of Computation by Rajesh K Shukla","Microcomputer System 8086 by Lice and gibson","Data Structure using C and C++ by Rajesh K Shukla","Data Structures Through C in Depth by SK Shrivastava","Data Structures through C by Yashwant Kanetkar","Object Oriented Programming with C++ by Balagurusamy"};
void redLight()
{
  digitalWrite (7,HIGH);
  delay(1500);
  digitalWrite(7,LOW);
}
void greenLight()
{
  digitalWrite (8,HIGH);
  delay(1500);
  digitalWrite(8,LOW);
}
void setup()
{
   Serial.begin(9600);  
   pinMode(8,OUTPUT);
   pinMode(7,OUTPUT);
}

void loop()
{
    String voice="";
    String b="";
    int f=0;
    delay(10);
    voice = Serial.readString();
 
    if(voice.length()>0)
    {
        Serial.println(voice);
        voice.toLowerCase();
          
        for(int i=0;i<70;i++)
        {
            b=books[i];
            b.toLowerCase();      
            if(voice==b)
            {
                //Serial.println("b="+b);
                //Serial.println("books[i]= "+books[i]);
                Serial.println("book is present in the library");
                f++;
                greenLight();
                break;
            }
        }
        if(f==0)
        {
          Serial.println("book is not present");
          redLight();
        }
    }
}
