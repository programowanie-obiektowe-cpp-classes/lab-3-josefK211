#pragma once

#include "Stocznia.hpp"

unsigned int transportujFlota(unsigned int towar)
{
    if (towar == 0)
        return 0; 
    Stocznia     stocznia;
    unsigned int przetransportowanyTowar = 0;
    unsigned int liczbaZaglowcow         = 0;

    while (przetransportowanyTowar < towar) {
        Statek* statek = stocznia(); 
        przetransportowanyTowar += statek->transportuj();

       
        if (dynamic_cast< Zaglowiec* >(statek) != nullptr) {
            ++liczbaZaglowcow;
        }

        delete statek; 
    }

    return liczbaZaglowcow;
}
