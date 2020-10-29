#include <QCoreApplication>
#include <QDebug>

class Persona : public QObject
{
public:
    Persona(QObject *padre = NULL)
                : QObject(padre)
    {

    }

    QString getNombre() const;
    void setNombre(const QString &value);

    int getEdad() const;
    void setEdad(int value);

    float getSalario() const;
    void setSalario(float value);

    ~Persona()
    {
        qDebug() << nombre << "Se ha eliminado";
    }

    void imprimir(){
        qDebug() << nombre << " " << edad << " " << salario;

    }

private:
    QString nombre;
    int edad;
    float salario;
};



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Persona * Manson = new Persona;
    Persona * Carlitos = new Persona(Manson);
    Persona * Laura = new Persona(Manson);
    Manson->setNombre("Manson");
    Manson->setEdad(45);
    Manson->setSalario(500.0);

    Carlitos->setNombre("Carlitos");
    Carlitos->setEdad(15);
    Carlitos->setSalario(10.0);

    Laura->setNombre("Laura");
    Laura->setEdad(10);
    Laura->setSalario(5.0);

    Manson->imprimir();
    Carlitos->imprimir();
    Laura->imprimir();

    delete Manson;
    return a.exec();
}

QString Persona::getNombre() const
{
return nombre;
}

void Persona::setNombre(const QString &value)
{
nombre = value;
}

int Persona::getEdad() const
{
return edad;
}

void Persona::setEdad(int value)
{
edad = value;
}

float Persona::getSalario() const
{
return salario;
}

void Persona::setSalario(float value)
{
salario = value;
}
