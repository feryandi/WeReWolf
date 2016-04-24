#include "handler.h"

handler::handler(QObject *parent) : QObject(parent)
{
	QObject::connect(&a, SIGNAL(valueChanged(int)), &b, SLOT(setValue(int)));
}

