
void intake_arm_k9(undefined8 param_1)

{
  undefined8 uVar1;
  undefined1 *unaff_RBX;
  
  uVar1 = (*(code *)&DAT_0ff4bdb0)(param_1,0x1b,7);
  *(undefined8 *)(unaff_RBX + 8) = uVar1;
  *unaff_RBX = 0xff;
  return;
}

