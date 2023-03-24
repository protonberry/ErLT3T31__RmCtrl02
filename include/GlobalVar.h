const int Vx[] = {0, 72, 72, 72, 72, 72, 72, 0}; //    0,SampleID,ProjectID,Test_ID,Blade,Recordflag,Load_Calibration_Factor
const int Vy[] = {0, 57, 73, 89, 105, 73, 89, 0};
const int Vw[] = {0, 57, 57, 57, 57, 57, 57, 0};
const int Vh[] = {0, 15, 15, 15, 15, 15, 15, 0};
const int Vnd[] = {0, 3, 2, 3, 1, 1, 4, 1};
const int VmaxVal[] = {0, 999, 99, 999, 2, 3, 9999, 0};
const int VminVal[] = {0, 0, 0, 0, 0, 0, 0, 0};
static volatile uint8_t Vsel = 0;
static volatile uint8_t NumFields = 0;
static volatile uint8_t FieldStart = 0;
static volatile int FieldVal[] = {0, 0, 0, 0, 0, 0, 0, 0};

const float VaneBladeCon[] = {550.04, 314.31, 68.75};
const char *VaneBladeDes[] = {".5x.5", ".5x1", "1x1"};
const char *RECdes[] = {"NO REC", "U only", "U+F+R", "U + R"};
float SamplingRate = 3. ;
float BladeDegPerMin = 90.;
float TestDurationDeg = 30.;
bool MultiTestSeq = false;
float ReleaseTorqueRot = 2.5;
float UDBladeDegPerMin = 25.;
float UDTestDurationDeg = 90.; //
float FastBladeDegPerMin = 900.;
float FastTestDurationDeg = 1800.; //
float ResBladeDegPerMin = 25.;
float ResTestDurationDeg = 90.; //

#define EEPROM_SIZE 512
uint8_t eeAddress = 0;
uint8_t eeAddress100 = 100;

// EEprom Variables
char sSerial_No[] = "            ";
int Load_Calibration_Factor = 1120; // converts readings to gm, make editable, divided by 10 for LC init
// float Load_Calibration_Factor = 112.0; //converts readings to gm
float Torque_Calibration_Factor = .001812; // 0.001793 ;
float AllowableLoadgm = 0.;
float AllowableTorque = 5.;
float xAllowableLoadgm = 150000.;
float CautionLoadgm = 0.;
char Serial_No[] = "            ";
volatile int Test_ID = 0;
volatile int SampleID = 8;
volatile int ProjectID = 3;
volatile int Blade = 2;
volatile int Recordflag = 2;
volatile bool Locked = false;
volatile bool MenuChgFlag = true;
volatile uint8_t Msel = 0;
static volatile uint8_t Mmax = 6;
volatile int Bcode = 0;           // 10s digit is button, 1s is function
volatile bool Tareflag = false;   // true is tare, false do nothing
volatile bool TorMaxflag = false; // true is Max torque stop test
volatile bool TestinProgress = false;
volatile int EditFieldsFlag = 0;
volatile int NumRDtoAvg = 3;
volatile float Wtgm = 0.;
volatile float MaxSx = 0.;
volatile float rotAtMax = 0.;
volatile float PrevWtgm = 0.;
volatile int TareCnt = 20;
volatile double StepCounter = 0;
volatile double MaxStepCounter = 0;
volatile int PressCnt = 0;
volatile int TestStage = 1;
volatile bool NewMVdata = false ;

int S2YPosSampleID ;
int S2YPosProjectID ;
int S2YPosLastSeq ;
int S2YPosBld ;

int S3YPosSS ;
int S3YPosBld ;
int S3YPosfn ;
int S3YPosSu ;
int S3YPosRot ;
int S3YPosMaxSu ;

int S4YPosBld ;
int S4YPosfn ;
int S4YPosS ;
int S4YPosRot ;
int S4YPosMaxSu ;
int S4YPosMaxSr ;

int S5YPosMaxTorque ;

int S6YPosRecData ;
int S6YPosCalFactor ;
