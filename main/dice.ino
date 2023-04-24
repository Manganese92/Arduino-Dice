#define LEDhautgauche 7
#define LEDhautmilieu 8 
#define LEDhautdroite 9   
#define LEDcentre 5 
#define LEDbasgauche 3
#define LEDbasmilieu 4 
#define LEDbasdroite 6  

#define BUTTON_PORT 2
#define BUZZER_PIN 10 
boolean buttonWasUp = true;
bool buttonState = false; // L'état initial du bouton poussoir (éteint)
int nbalea; // Variable du nombre aléatoire 



void setup() {
  // put your setup code here, to run once:
  pinMode(LEDhautgauche, OUTPUT);
  pinMode(LEDhautmilieu, OUTPUT);
  pinMode(LEDhautdroite, OUTPUT);  
  pinMode(LEDcentre, OUTPUT); 
  pinMode(LEDbasgauche, OUTPUT);
  pinMode(LEDbasmilieu, OUTPUT);  
  pinMode(LEDbasdroite, OUTPUT); 

  pinMode(BUZZER_PIN, OUTPUT); 
  pinMode(BUTTON_PORT, INPUT_PULLUP);
  randomSeed(analogRead(0)); // Création de l'aléatoire
}



void loop() {
  // put your main code here, to run repeatedly:


  // Condition 1 : bouton appuyé ET état actuel du bouton éteint
  if (digitalRead(BUTTON_PORT) == LOW && buttonState == false) {
    nbalea = random (1,6); // Choix du nombre aléatoire 
    playRollingSoundAndLight(); // Joue l'animation
    delay(300); // Antend 3 sec le temps que la musique ce termine pour afficher le résultat
    de(nbalea); //Permet d'allumer les leds suivant le numéro random stocké dans "nbalea"
    buttonState = true;  // Changement de l'état : de false à true 
    delay(100); // Attend 1 seconde
  }

  // Condition 2 : bouton appuyé ET état actuel du bouton allumé
  if (digitalRead(BUTTON_PORT) == LOW && buttonState == true) {
    buttonState = false; // Changement de l'état du bouton à false
    delay(100); // Attend 1 seconde
  }

}


////////////////////////////////////////////////
// Affichage du resultat du dé avec des LED ///
//////////////////////////////////////////////

void de (int value) {

  switch (value) {

    case 1:
      digitalWrite (LEDhautgauche, LOW); // Eteinte
      digitalWrite (LEDhautmilieu, LOW); // Eteinte
      digitalWrite (LEDhautdroite, LOW); // Eteinte
      digitalWrite (LEDcentre, HIGH); // Allumée
      digitalWrite (LEDbasgauche, LOW); // Eteinte
      digitalWrite (LEDbasmilieu, LOW); // Eteinte
      digitalWrite (LEDbasdroite, LOW); // Eteinte
      break;

    case 2:
      digitalWrite (LEDhautgauche, HIGH); // Allumée
      digitalWrite (LEDhautmilieu, LOW); // Eteinte
      digitalWrite (LEDhautdroite, LOW); // Eteinte
      digitalWrite (LEDcentre, LOW); // Eteinte
      digitalWrite (LEDbasgauche, LOW); // Eteinte
      digitalWrite (LEDbasmilieu, LOW); // Eteinte
      digitalWrite (LEDbasdroite, HIGH); // Allumée
      break;

    case 3:
      digitalWrite (LEDhautgauche, HIGH); // Allumée
      digitalWrite (LEDhautmilieu, LOW); // Eteinte
      digitalWrite (LEDhautdroite, LOW); // Eteinte
      digitalWrite (LEDcentre, HIGH); // Allumée
      digitalWrite (LEDbasgauche, LOW); // Eteinte
      digitalWrite (LEDbasmilieu, LOW); // Eteinte
      digitalWrite (LEDbasdroite, HIGH); // Allumée
      break;
        
    case 4:
      digitalWrite (LEDhautgauche, HIGH); // Allumée
      digitalWrite (LEDhautmilieu, LOW); // Eteinte
      digitalWrite (LEDhautdroite, HIGH); // Allumée
      digitalWrite (LEDcentre, LOW); // Eteinte
      digitalWrite (LEDbasgauche, HIGH); // Allumée
      digitalWrite (LEDbasmilieu, LOW); // Eteinte
      digitalWrite (LEDbasdroite, HIGH); // Allumée
      break;

    case 5:
      digitalWrite (LEDhautgauche, HIGH); // Allumée
      digitalWrite (LEDhautmilieu, LOW); // Eteinte
      digitalWrite (LEDhautdroite, HIGH); // Allumée
      digitalWrite (LEDcentre, HIGH); // Allumée
      digitalWrite (LEDbasgauche, HIGH); // Allumée
      digitalWrite (LEDbasmilieu, LOW); // Eteinte
      digitalWrite (LEDbasdroite, HIGH); // Allumée
      break;

    case 6:
      digitalWrite (LEDhautgauche, HIGH); // Allumée
      digitalWrite (LEDhautmilieu, HIGH); // Allumée
      digitalWrite (LEDhautdroite, HIGH); // Allumée
      digitalWrite (LEDcentre, LOW); // Eteinte
      digitalWrite (LEDbasgauche, HIGH); // Allumée
      digitalWrite (LEDbasmilieu, HIGH); // Allumée
      digitalWrite (LEDbasdroite, HIGH); // Allumée
      break;
  }
}




/////////////////////////////////////////////////
// Animation bruit et lumières lors du lancé ///
///////////////////////////////////////////////

void playRollingSoundAndLight() {
  for (int i = 0; i < 12; i++) {
    tone(BUZZER_PIN, random(200, 1000), 50); // Fréquence alétoire entre 200 et 1000 Hz avec une durée de 50ms
    
    // Allumage ligne du haut
    digitalWrite(LEDhautgauche, HIGH);
    digitalWrite(LEDhautmilieu, HIGH);
    digitalWrite(LEDhautdroite, HIGH);
    delay(100);
    digitalWrite(LEDhautgauche, LOW);
    digitalWrite(LEDhautmilieu, LOW);
    digitalWrite(LEDhautdroite, LOW);
  
    // Allumage ligne du milieu
    digitalWrite(LEDcentre, HIGH);
    delay(100);
    digitalWrite(LEDcentre, LOW);
  
    // Allumage ligne du bas
    digitalWrite(LEDbasgauche, HIGH);
    digitalWrite(LEDbasmilieu, HIGH);
    digitalWrite(LEDbasdroite, HIGH);
    delay(100);
    digitalWrite(LEDbasgauche, LOW);
    digitalWrite(LEDbasmilieu, LOW);
    digitalWrite(LEDbasdroite, LOW);

    delay(100);
    noTone(BUZZER_PIN); // Stop le signal sonore
    delay(100);
  }
}