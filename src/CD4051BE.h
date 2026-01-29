class CD4051BE {
  private:
    // These variables will "remember" the pins for the life of the object
    int _pinA;
    int _pinB;
    int _pinC;

  public:
    // The Constructor takes the pins as arguments
    CD4051BE(int pinA, int pinB, int pinC);

    void begin();
    void selectChannel(int channel);
};