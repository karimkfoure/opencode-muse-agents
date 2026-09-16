
undefined8 * owner_driver_A(undefined8 *param_1,undefined8 param_2,int param_3)

{
  undefined8 uStack_38;
  undefined8 uStack_30;
  undefined8 uStack_28;
  undefined1 uStack_19;
  
  owner_child_control(&uStack_38);
  if (param_3 == 0) {
    func_0x07abbdc0(&uStack_38,&uStack_19);
  }
  param_1[2] = uStack_28;
  *param_1 = uStack_38;
  param_1[1] = uStack_30;
  return param_1;
}

