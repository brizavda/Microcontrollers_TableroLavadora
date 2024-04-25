class BotonNivelAgua {
private:
    uint BOTON_GPIO;
public:
    BotonNivelAgua(uint gpio);
    bool is_pressed();
    void control_nivel_agua();
};
