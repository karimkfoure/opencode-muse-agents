
void steering_intake_arm(void)

{
  long unaff_RBP;
  
  *(undefined **)(unaff_RBP + -0xa0) = &UNK_0067375f;
  *(undefined8 *)(unaff_RBP + -0x98) = 0x1b;
  *(undefined **)(unaff_RBP + -0x90) = &UNK_0021ef60;
  *(undefined8 *)(unaff_RBP + -0x88) = 0x10;
  *(undefined **)(unaff_RBP + -0x80) = &UNK_0026a46c;
  *(undefined8 *)(unaff_RBP + -0x78) = 4;
  *(undefined **)(unaff_RBP + -0x70) = &UNK_0067377a;
  *(undefined8 *)(unaff_RBP + -0x68) = 0x11;
  func_0x079ba800();
  return;
}

