int D0 = 0;
int D1 = 0;
int S = 0;
int bitcount = 0;
int output = 0;
void setup() {
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()>0) {
    char c = Serial.read();
    if(c=='0' || c=='1') {
      int bit = c - '0';
      if( bitcount==0) {
        D0 = bit;
        bitcount = 1;
      }
      else if (bitcount==1) {
        D1 = bit;
        bitcount = 2;
      }
      else if(bitcount==2) {
        S = bit;
        bitcount = 3;
      }
      if(bitcount==3) {
        output = (D0 & (1 - S)) | (D1 & S);
        digitalWrite(7,D0);
        digitalWrite(8,D1);
        if(output==1) {
          digitalWrite(9,1);
        }
        delay(1500);
        digitalWrite(7,0);
        digitalWrite(8,0);
        digitalWrite(9,0);
        bitcount = 0;
        while(Serial.available() > 0) {
          Serial.read();
          }
        }
      }
    }
  }
