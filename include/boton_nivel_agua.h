class Boton_nivel_agua {
private:
    uint BUTTON_GPIO;
public:
    Boton_nivel_agua(uint gpio);
    bool is_pressed();
    void water_level_control();
};

