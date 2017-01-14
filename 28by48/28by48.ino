
 #include <Stepper.h>
 #define STEPS 64
  

  Stepper small_stepper(STEPS, 8, 10, 9, 11);     // Sens horaire
  

  int  Steps2Take = 0;  //Nombre de pas de rotation demandé au moteur
  long temps =0;          //Durée de rotation pour un tour

  
void setup() 
 {                
  Serial.begin(9600);     // 9600 bps
  Serial.println("Test de moteur pas a pas");  
  }

void loop() 
  {
  Serial.println("Moteur en marche ");  
  small_stepper.setSpeed(300); //Vitesse de 300 (max) réduire ce chiffre pour un mouvement plus lent
  
  Steps2Take  = -1000;  // Une rotation complète avec 2048 pas (1 tour environ 4.5sec)
  temps = millis();
  small_stepper.step(Steps2Take);  //Ca tourne
  temps =  millis()- temps ;  //Chronomètre un rour complet  6.236 sec par tour à vitesse 200
  Serial.println(temps);      //Affiche le temps (en ms) pour un tour complet
  delay(2000);  //pause
  
  
 }