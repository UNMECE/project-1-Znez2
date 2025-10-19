#ifndef CAPACITOR_H
#define CAPACITOR_H

struct _capacitor {
  double *time;      // array of time points
  double *voltage;   // array of voltages
  double *current;   // array of currents
  double C;          // capacitance value
};
typedef struct _capacitor Capacitor;

#endif

