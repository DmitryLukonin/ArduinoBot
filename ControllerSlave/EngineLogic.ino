        // ======================================================== Motor's logic =================================================

void MoveStop()
{
  digitalWrite(MRDf, 0);  
  digitalWrite(MRDb, 0);
  digitalWrite(MLDf, 0);  
  digitalWrite(MLDb, 0);
}

void MoveForvard()
{
  MRf();
  MLf();
}

void MoveBack()
{
  MRb();
  MLb();
  ConfigureTriger(2,EngineTimeBack);
}

void MoveRight()
{
  MRb();
  MLf();
  ConfigureTriger(2,2000);
}

void MoveLeft()
{
  MRf();
  MLb();
  ConfigureTriger(2,EngineTimeTurn);
}

void MoveRightTurn()
{
  MRb();
    ConfigureTriger(2,2000);
}

void MoveLeftTurn()
{
  MLf();
}

void MoveFullTurnLeft()
{
  MRf();
  MLb();
  ConfigureTriger(2,EngineTimeTurnFull);
}

void MoveFullTurnRight()
{
  MRb();
  MLf();
  ConfigureTriger(2,EngineTimeTurnFull);
}

void MRf()    // правый мотор вперед
{   
  digitalWrite(MRDf, 1);  
  digitalWrite(MRDb, 0);
}
void MRb()    // правый мотор назад
{  
  digitalWrite(MRDf, 0);  
  digitalWrite(MRDb, 1);
}
void MLf()    // левый мотор вперед
{  
  digitalWrite(MLDf, 1);  
  digitalWrite(MLDb, 0);
}
void MLb()    // правый мотор назад
{   
  digitalWrite(MLDf, 0);  
  digitalWrite(MLDb, 1);
}
