//four digital pin and two pwm pin

class motor_drive
{
  private:

    int in1,in2,in3,in4,speed_pin1,speed_pin2,speed_value=255;
    char front_='5',back_='7',left_='3',right_='1',stop_='0';

  public:
   /*
    * four pin for motor drivers four pin
    */
    motor_drive(int in1,int in2,int in3,int in4)
    {
      this->in1=in1;
      this->in2=in2;
      this->in3=in3;
      this->in4=in4;

      pinMode(in1,OUTPUT);
      pinMode(in2,OUTPUT);
      pinMode(in3,OUTPUT);
      pinMode(in4,OUTPUT);
    }
//constructor with speed parameter

/*
 * first four parameter for four pin of  motor driver
 * second two pin for two pwm pin
 * last one is for pwm value or the speed value
 */

    motor_drive(int in1,int in2,int in3,int in4,\
                int speed_pin1,int speed_pin2,\
                int speed_value=255)
    {
      this->in1=in1;
      this->in2=in2;
      this->in3=in3;
      this->in4=in4;

      this->speed_pin1=speed_pin1;
      this->speed_pin2=speed_pin2;

      pinMode(in1,OUTPUT);
      pinMode(in2,OUTPUT);
      pinMode(in3,OUTPUT);
      pinMode(in4,OUTPUT);

      analogWrite(this->speed_pin1,speed_value);
      analogWrite(this->speed_pin2,speed_value);

    }

    bool set_speed(int speed_value)
    {
      this->speed_value=speed_value;

      analogWrite(speed_pin1,this->speed_value);
      analogWrite(speed_pin2,this->speed_value);

    }

    bool left()
    {
      digitalWrite(this->in1,HIGH);
      digitalWrite(this->in2,LOW);

      digitalWrite(this->in3,LOW);
      digitalWrite(this->in4,HIGH);
    }

    bool right()
    {
      digitalWrite(this->in1,LOW);
      digitalWrite(this->in2,HIGH);

      digitalWrite(this->in3,HIGH);
      digitalWrite(this->in4,LOW);
    }

    bool back()
    {
      digitalWrite(this->in1,HIGH);
      digitalWrite(this->in2,LOW);

      digitalWrite(this->in3,HIGH);
      digitalWrite(this->in4,LOW);
    }

    bool front()
    {
      digitalWrite(this->in1,LOW);
      digitalWrite(this->in2,HIGH);

      digitalWrite(this->in3,LOW);
      digitalWrite(this->in4,HIGH);
    }

    bool stop_mov()
    {
      digitalWrite(this->in1,LOW);
      digitalWrite(this->in2,LOW);

      digitalWrite(this->in3,LOW);
      digitalWrite(this->in4,LOW);
    }

    bool command( char com )
    {
      if( com == this -> front_ )
      {
        this->front();
      }
      else if( com == this -> back_ )
      {
        this -> back();
      }
      else if( com == this -> right_ )
      {
        this -> right();
      }
      else if( com == this -> left_ )
      {
        this -> left();
      }
      else if(com == this->stop_)
      {
        this->stop_mov();
      }
      else if(com == '+')
      {
        if(this->speed_value<=255)
        {
          this->speed_value++;
          analogWrite(this->speed_pin1,speed_value);
          analogWrite(this->speed_pin2,speed_value);
        }


      }
      else if(com == '-')
      {
        if(this->speed_value>=0)
        {
          this->speed_value--;
          analogWrite(this->speed_pin1,speed_value);
        analogWrite(this->speed_pin2,speed_value);
        }

      }
    }

};
