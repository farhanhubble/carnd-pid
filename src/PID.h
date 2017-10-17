#ifndef PID_H
#define PID_H

class PID {
public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;


  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;

  double delta_Kp;
  double delta_Ki;
  double delta_Kd;


  double best_cte;
  double prev_cte;
  double integral_cte;

  bool initialized;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd, double cte);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();

  void UpdateCoeffs(double cte);
};

#endif /* PID_H */
