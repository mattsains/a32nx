#ifndef RTW_HEADER_Autopilot_h_
#define RTW_HEADER_Autopilot_h_
#include <cfloat>
#include <cmath>
#include <cstring>
#ifndef Autopilot_COMMON_INCLUDES_
# define Autopilot_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif

#include "Autopilot_types.h"

typedef struct {
  uint8_T is_active_c1_Autopilot;
  uint8_T is_c1_Autopilot;
} rtDW_Chart_Autopilot_T;

typedef struct {
  real_T u;
  real_T LAW;
} BlockIO_Autopilot_T;

typedef struct {
  real_T Delay_DSTATE;
  real_T Delay_DSTATE_c;
  real_T Delay1_DSTATE;
  real_T Delay_DSTATE_h;
  real_T Delay_DSTATE_j;
  real_T Delay1_DSTATE_f;
  real_T Delay_DSTATE_cq;
  real_T Delay_DSTATE_g;
  real_T Delay_DSTATE_l;
  real_T Delay1_DSTATE_g;
  real_T Delay_DSTATE_j4;
  real_T Delay_DSTATE_e;
  real_T Delay1_DSTATE_l;
  real_T Delay_DSTATE_p;
  real_T Delay_DSTATE_n;
  real_T Delay1_DSTATE_h;
  real_T Delay_DSTATE_b;
  real_T Delay_DSTATE_f;
  real_T Delay1_DSTATE_a;
  real_T Delay_DSTATE_o;
  real_T loc_trk_time;
  uint8_T icLoad;
  uint8_T icLoad_b;
  uint8_T is_active_c10_Autopilot;
  uint8_T is_c10_Autopilot;
  uint8_T is_active_c3_Autopilot;
  uint8_T is_c3_Autopilot;
  uint8_T is_active_c5_Autopilot;
  uint8_T is_c5_Autopilot;
  uint8_T is_active_c6_Autopilot;
  uint8_T is_c6_Autopilot;
  uint8_T is_LOC;
  boolean_T IC_FirstOutputTime;
  boolean_T IC_FirstOutputTime_h;
  boolean_T IC_FirstOutputTime_hq;
  boolean_T IC_FirstOutputTime_n;
  boolean_T IC_FirstOutputTime_l;
  boolean_T IC_FirstOutputTime_e;
  rtDW_Chart_Autopilot_T sf_Chart_a;
  rtDW_Chart_Autopilot_T sf_Chart_f;
  rtDW_Chart_Autopilot_T sf_Chart_k;
  rtDW_Chart_Autopilot_T sf_Chart_o;
  rtDW_Chart_Autopilot_T sf_Chart_b;
  rtDW_Chart_Autopilot_T sf_Chart_j;
  rtDW_Chart_Autopilot_T sf_Chart_d;
} D_Work_Autopilot_T;

typedef struct {
  ap_input in;
} ExternalInputs_Autopilot_T;

typedef struct {
  ap_output out;
} ExternalOutputs_Autopilot_T;

struct Parameters_Autopilot_T_ {
  ap_output ap_output_MATLABStruct;
  real_T ScheduledGain_BreakpointsForDimension1[4];
  real_T ScheduledGain_BreakpointsForDimension1_n[4];
  real_T ScheduledGain_BreakpointsForDimension1_l[4];
  real_T ScheduledGain_BreakpointsForDimension1_lw[4];
  real_T ScheduledGain_BreakpointsForDimension1_e[5];
  real_T ScheduledGain_BreakpointsForDimension1_j[4];
  real_T ScheduledGain_BreakpointsForDimension1_h[5];
  real_T LagFilter_C1;
  real_T LagFilter_C1_l;
  real_T LagFilter1_C1;
  real_T LagFilter_C1_n;
  real_T LagFilter1_C1_p;
  real_T LagFilter_C1_g;
  real_T DiscreteDerivativeVariableTs_Gain;
  real_T DiscreteDerivativeVariableTs_Gain_m;
  real_T DiscreteDerivativeVariableTs_Gain_l;
  real_T DiscreteDerivativeVariableTs_Gain_lf;
  real_T DiscreteDerivativeVariableTs_InitialCondition;
  real_T RateLimiterVariableTs_InitialCondition;
  real_T DiscreteDerivativeVariableTs_InitialCondition_e;
  real_T DiscreteDerivativeVariableTs_InitialCondition_h;
  real_T DiscreteDerivativeVariableTs_InitialCondition_b;
  real_T RateLimiterVariableTs_InitialCondition_p;
  real_T ScheduledGain_Table[4];
  real_T ScheduledGain_Table_b[4];
  real_T ScheduledGain_Table_k[4];
  real_T ScheduledGain_Table_g[4];
  real_T ScheduledGain_Table_p[5];
  real_T ScheduledGain_Table_l[4];
  real_T ScheduledGain_Table_i[5];
  real_T CompareToConstant_const;
  real_T CompareToConstant_const_j;
  real_T RateLimiterVariableTs_lo;
  real_T RateLimiterVariableTs_lo_o;
  real_T RateLimiterVariableTs_up;
  real_T RateLimiterVariableTs_up_i;
  real_T Constant_Value;
  real_T Gain_Gain;
  real_T Gain5_Gain;
  real_T Constant1_Value;
  real_T Gain_Gain_a;
  real_T beta_Value;
  real_T beta_Value_m;
  real_T beta_Value_b;
  real_T beta_Value_e;
  real_T Constant3_Value;
  real_T Gain1_Gain;
  real_T Gain1_Gain_b;
  real_T Gain1_Gain_o;
  real_T msftmin_Gain;
  real_T Constant_Value_p;
  real_T Constant3_Value_n;
  real_T ftmintoms_Gain;
  real_T Gain_Gain_i;
  real_T Gain_Gain_k;
  real_T Constant2_Value;
  real_T Gain4_Gain;
  real_T Switch_Threshold;
  real_T Gain1_Gain_i;
  real_T Gain_Gain_c;
  real_T Gain1_Gain_k;
  real_T Gain1_Gain_h;
  real_T msftmin_Gain_b;
  real_T ftmintoms_Gain_h;
  real_T Gain_Gain_m;
  real_T Gain_Gain_ms;
  real_T Switch_Threshold_k;
  real_T Gain1_Gain_ii;
  real_T Gain1_Gain_m;
  real_T msftmin_Gain_n;
  real_T Constant_Value_b;
  real_T Gain_Gain_e;
  real_T ftmintoms_Gain_f;
  real_T Gain_Gain_j;
  real_T Gain_Gain_p;
  real_T Gain1_Gain_g;
  real_T Gain1_Gain_e;
  real_T msftmin_Gain_f;
  real_T Gain_Gain_f;
  real_T Saturation_UpperSat;
  real_T Saturation_LowerSat;
  real_T ftmintoms_Gain_b;
  real_T Gain_Gain_g;
  real_T Gain_Gain_c1;
  real_T Constant_Value_j;
  real_T Y_Y0;
  real_T Gain1_Gain_el;
  real_T GainTheta_Gain;
  real_T GainTheta1_Gain;
  real_T Gain_Gain_l;
  real_T Gainqk_Gain;
  real_T Gain_Gain_aq;
  real_T Gain_Gain_kc;
  real_T Gainpk_Gain;
  real_T Gain_Gain_af;
  real_T Constant1_Value_p;
  real_T Saturation_UpperSat_k;
  real_T Saturation_LowerSat_m;
  real_T Gain1_Gain_k1;
  real_T Saturation1_UpperSat;
  real_T Saturation1_LowerSat;
  real_T Constant3_Value_e;
  real_T Gain_Gain_h;
  real_T Constant2_Value_l;
  real_T Constant3_Value_h;
  real_T Constant_Value_bl;
  real_T Gain1_Gain_ge;
  real_T Gain2_Gain;
  real_T Gain4_Gain_f;
  real_T Gain_Gain_n;
  real_T Constant1_Value_m;
  real_T ROLLLIM1_tableData[5];
  real_T ROLLLIM1_bp01Data[5];
  real_T Constant3_Value_m;
  real_T Gain_Gain_jz;
  real_T Constant_Value_c;
  real_T Constant3_Value_l;
  real_T Gain_Gain_i2;
  real_T Constant_Value_i;
  real_T Constant3_Value_nf;
  real_T Constant_Value_e;
  real_T Gain_Gain_nu;
  real_T Saturation_UpperSat_kr;
  real_T Saturation_LowerSat_p;
  real_T Gain2_Gain_f;
  real_T Gain1_Gain_n;
  real_T Gain_Gain_o;
  real_T Constant_Value_cw;
  real_T Constant3_Value_f;
  real_T Constant_Value_pl;
  real_T Gain1_Gain_j;
  real_T Gain2_Gain_n;
  real_T Saturation1_UpperSat_i;
  real_T Saturation1_LowerSat_g;
  real_T Gain3_Gain;
  real_T Gain_Gain_b;
  real_T Constant_Value_e5;
  real_T Constant3_Value_no;
  real_T Constant_Value_ef;
  real_T Gain3_Gain_i;
  real_T Delay_InitialCondition;
  real_T Constant_Value_g;
  real_T Delay1_InitialCondition;
  real_T Gain_Gain_k4;
  real_T Constant_Value_p1;
  real_T Gain_Gain_d;
  real_T Constant2_Value_h;
  real_T Gain1_Gain_kf;
  real_T Delay_InitialCondition_g;
  real_T Constant_Value_a;
  real_T Delay1_InitialCondition_n;
  real_T Saturation_UpperSat_n;
  real_T Saturation_LowerSat_a;
  real_T Constant_Value_cm;
  real_T kntoms_Gain;
  real_T IC_Value;
  real_T kntoms_Gain_e;
  real_T IC_Value_o;
  real_T Gain3_Gain_f;
  real_T Delay_InitialCondition_h;
  real_T Constant_Value_f;
  real_T Delay1_InitialCondition_g;
  real_T Saturation_UpperSat_h;
  real_T Saturation_LowerSat_c;
  real_T Gain1_Gain_bz;
  real_T Constant_Value_em;
  real_T Gain1_Gain_k0;
  real_T Gain1_Gain_ea;
  real_T Gain_Gain_f2;
  real_T Gain_Gain_pi;
  real_T Constant1_Value_e;
  real_T Gain_Gain_h4;
  real_T Constant_Value_k;
  real_T Gain1_Gain_bm;
  real_T Gain1_Gain_go;
  real_T kntoms_Gain_i;
  real_T msftmin_Gain_m;
  real_T ftmintoms_Gain_f0;
  real_T IC_Value_j;
  real_T Gain_Gain_kw;
  real_T Gain_Gain_bf;
  real_T kntoms_Gain_a;
  real_T IC_Value_i;
  real_T Gain1_Gain_jl;
  real_T Gain3_Gain_o;
  real_T Delay_InitialCondition_o;
  real_T Constant_Value_a0;
  real_T Delay1_InitialCondition_m;
  real_T kntoms_Gain_av;
  real_T IC_Value_n;
  real_T Constant1_Value_d;
  real_T Gain3_Gain_fd;
  real_T Delay_InitialCondition_l;
  real_T Constant_Value_be;
  real_T Delay1_InitialCondition_md;
  real_T Saturation_UpperSat_nk;
  real_T Saturation_LowerSat_h;
  real_T Gain1_Gain_p;
  real_T Constant_Value_jb;
  real_T Gain1_Gain_k4;
  real_T Gain1_Gain_mv;
  real_T Gain_Gain_dj;
  real_T Gain_Gain_c3;
  real_T Constant1_Value_l;
  real_T Gain_Gain_hk;
  real_T Constant_Value_in;
  real_T Gain1_Gain_a;
  real_T Gain1_Gain_nc;
  real_T kntoms_Gain_f;
  real_T msftmin_Gain_by;
  real_T ftmintoms_Gain_fr;
  real_T IC_Value_p;
  real_T Gain_Gain_cd;
  real_T Gain_Gain_js;
  real_T Constant1_Value_i;
  real_T Constant2_Value_h1;
  real_T Gain1_Gain_kl;
  real_T Delay_InitialCondition_ll;
  real_T Constant_Value_ja;
  real_T Delay1_InitialCondition_b;
  real_T Saturation_UpperSat_f;
  real_T Saturation_LowerSat_f;
  real_T Constant_Value_g4;
  uint8_T ManualSwitch_CurrentSetting;
  uint8_T ManualSwitch_CurrentSetting_b;
};

extern const ap_input Autopilot_rtZap_input;
extern const ap_output Autopilot_rtZap_output;
class AutopilotModelClass {
 public:
  ExternalInputs_Autopilot_T Autopilot_U;
  ExternalOutputs_Autopilot_T Autopilot_Y;
  void initialize();
  void step();
  void terminate();
  AutopilotModelClass();
  ~AutopilotModelClass();
 private:
  static Parameters_Autopilot_T Autopilot_P;
  BlockIO_Autopilot_T Autopilot_B;
  D_Work_Autopilot_T Autopilot_DWork;
  void Autopilot_Chart_Init(rtDW_Chart_Autopilot_T *localDW);
  void Autopilot_Chart(real_T rtu_right, real_T rtu_left, real_T rtu_use_short_path, real_T *rty_out,
                       rtDW_Chart_Autopilot_T *localDW);
};

#endif

