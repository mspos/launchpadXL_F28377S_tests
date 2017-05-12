################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
F2837xS_CodeStartBranch.obj: /home/matteo/ti/C2000Ware_1_00_00_00_Software/device_support/f2837xs/common/source/F2837xS_CodeStartBranch.asm $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/home/matteo/CCS/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 --include_path="/home/matteo/workspace_v7/launchpadXL_F28377S_tests/launchpadXL_progressive_tests" --include_path="/home/matteo/CCS/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/include" --include_path="/home/matteo/workspace_v7/launchpadXL_F28377S_tests/launchpadXL_progressive_tests/inc" --include_path="/home/matteo/ti/C2000Ware_1_00_00_00_Software/device_support/f2837xs/common/include" --include_path="/home/matteo/ti/C2000Ware_1_00_00_00_Software/device_support/f2837xs/headers/include" --define=CPU1 --define=_LAUNCHXL_F28377S --define=_FLASH -g --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="F2837xS_CodeStartBranch.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

F2837xS_CpuTimers.obj: /home/matteo/ti/C2000Ware_1_00_00_00_Software/device_support/f2837xs/common/source/F2837xS_CpuTimers.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/home/matteo/CCS/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 --include_path="/home/matteo/workspace_v7/launchpadXL_F28377S_tests/launchpadXL_progressive_tests" --include_path="/home/matteo/CCS/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/include" --include_path="/home/matteo/workspace_v7/launchpadXL_F28377S_tests/launchpadXL_progressive_tests/inc" --include_path="/home/matteo/ti/C2000Ware_1_00_00_00_Software/device_support/f2837xs/common/include" --include_path="/home/matteo/ti/C2000Ware_1_00_00_00_Software/device_support/f2837xs/headers/include" --define=CPU1 --define=_LAUNCHXL_F28377S --define=_FLASH -g --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="F2837xS_CpuTimers.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

F2837xS_DefaultISR.obj: /home/matteo/ti/C2000Ware_1_00_00_00_Software/device_support/f2837xs/common/source/F2837xS_DefaultISR.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/home/matteo/CCS/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 --include_path="/home/matteo/workspace_v7/launchpadXL_F28377S_tests/launchpadXL_progressive_tests" --include_path="/home/matteo/CCS/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/include" --include_path="/home/matteo/workspace_v7/launchpadXL_F28377S_tests/launchpadXL_progressive_tests/inc" --include_path="/home/matteo/ti/C2000Ware_1_00_00_00_Software/device_support/f2837xs/common/include" --include_path="/home/matteo/ti/C2000Ware_1_00_00_00_Software/device_support/f2837xs/headers/include" --define=CPU1 --define=_LAUNCHXL_F28377S --define=_FLASH -g --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="F2837xS_DefaultISR.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

F2837xS_GlobalVariableDefs.obj: /home/matteo/ti/C2000Ware_1_00_00_00_Software/device_support/f2837xs/headers/source/F2837xS_GlobalVariableDefs.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/home/matteo/CCS/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 --include_path="/home/matteo/workspace_v7/launchpadXL_F28377S_tests/launchpadXL_progressive_tests" --include_path="/home/matteo/CCS/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/include" --include_path="/home/matteo/workspace_v7/launchpadXL_F28377S_tests/launchpadXL_progressive_tests/inc" --include_path="/home/matteo/ti/C2000Ware_1_00_00_00_Software/device_support/f2837xs/common/include" --include_path="/home/matteo/ti/C2000Ware_1_00_00_00_Software/device_support/f2837xs/headers/include" --define=CPU1 --define=_LAUNCHXL_F28377S --define=_FLASH -g --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="F2837xS_GlobalVariableDefs.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

F2837xS_Gpio.obj: /home/matteo/ti/C2000Ware_1_00_00_00_Software/device_support/f2837xs/common/source/F2837xS_Gpio.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/home/matteo/CCS/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 --include_path="/home/matteo/workspace_v7/launchpadXL_F28377S_tests/launchpadXL_progressive_tests" --include_path="/home/matteo/CCS/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/include" --include_path="/home/matteo/workspace_v7/launchpadXL_F28377S_tests/launchpadXL_progressive_tests/inc" --include_path="/home/matteo/ti/C2000Ware_1_00_00_00_Software/device_support/f2837xs/common/include" --include_path="/home/matteo/ti/C2000Ware_1_00_00_00_Software/device_support/f2837xs/headers/include" --define=CPU1 --define=_LAUNCHXL_F28377S --define=_FLASH -g --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="F2837xS_Gpio.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

F2837xS_PieCtrl.obj: /home/matteo/ti/C2000Ware_1_00_00_00_Software/device_support/f2837xs/common/source/F2837xS_PieCtrl.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/home/matteo/CCS/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 --include_path="/home/matteo/workspace_v7/launchpadXL_F28377S_tests/launchpadXL_progressive_tests" --include_path="/home/matteo/CCS/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/include" --include_path="/home/matteo/workspace_v7/launchpadXL_F28377S_tests/launchpadXL_progressive_tests/inc" --include_path="/home/matteo/ti/C2000Ware_1_00_00_00_Software/device_support/f2837xs/common/include" --include_path="/home/matteo/ti/C2000Ware_1_00_00_00_Software/device_support/f2837xs/headers/include" --define=CPU1 --define=_LAUNCHXL_F28377S --define=_FLASH -g --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="F2837xS_PieCtrl.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

F2837xS_PieVect.obj: /home/matteo/ti/C2000Ware_1_00_00_00_Software/device_support/f2837xs/common/source/F2837xS_PieVect.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/home/matteo/CCS/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 --include_path="/home/matteo/workspace_v7/launchpadXL_F28377S_tests/launchpadXL_progressive_tests" --include_path="/home/matteo/CCS/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/include" --include_path="/home/matteo/workspace_v7/launchpadXL_F28377S_tests/launchpadXL_progressive_tests/inc" --include_path="/home/matteo/ti/C2000Ware_1_00_00_00_Software/device_support/f2837xs/common/include" --include_path="/home/matteo/ti/C2000Ware_1_00_00_00_Software/device_support/f2837xs/headers/include" --define=CPU1 --define=_LAUNCHXL_F28377S --define=_FLASH -g --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="F2837xS_PieVect.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

F2837xS_SysCtrl.obj: /home/matteo/ti/C2000Ware_1_00_00_00_Software/device_support/f2837xs/common/source/F2837xS_SysCtrl.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/home/matteo/CCS/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 --include_path="/home/matteo/workspace_v7/launchpadXL_F28377S_tests/launchpadXL_progressive_tests" --include_path="/home/matteo/CCS/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/include" --include_path="/home/matteo/workspace_v7/launchpadXL_F28377S_tests/launchpadXL_progressive_tests/inc" --include_path="/home/matteo/ti/C2000Ware_1_00_00_00_Software/device_support/f2837xs/common/include" --include_path="/home/matteo/ti/C2000Ware_1_00_00_00_Software/device_support/f2837xs/headers/include" --define=CPU1 --define=_LAUNCHXL_F28377S --define=_FLASH -g --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="F2837xS_SysCtrl.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

F2837xS_struct.obj: /home/matteo/ti/C2000Ware_1_00_00_00_Software/device_support/f2837xs/common/source/F2837xS_struct.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/home/matteo/CCS/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 --include_path="/home/matteo/workspace_v7/launchpadXL_F28377S_tests/launchpadXL_progressive_tests" --include_path="/home/matteo/CCS/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/include" --include_path="/home/matteo/workspace_v7/launchpadXL_F28377S_tests/launchpadXL_progressive_tests/inc" --include_path="/home/matteo/ti/C2000Ware_1_00_00_00_Software/device_support/f2837xs/common/include" --include_path="/home/matteo/ti/C2000Ware_1_00_00_00_Software/device_support/f2837xs/headers/include" --define=CPU1 --define=_LAUNCHXL_F28377S --define=_FLASH -g --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="F2837xS_struct.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

F2837xS_usDelay.obj: /home/matteo/ti/C2000Ware_1_00_00_00_Software/device_support/f2837xs/common/source/F2837xS_usDelay.asm $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/home/matteo/CCS/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 --include_path="/home/matteo/workspace_v7/launchpadXL_F28377S_tests/launchpadXL_progressive_tests" --include_path="/home/matteo/CCS/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/include" --include_path="/home/matteo/workspace_v7/launchpadXL_F28377S_tests/launchpadXL_progressive_tests/inc" --include_path="/home/matteo/ti/C2000Ware_1_00_00_00_Software/device_support/f2837xs/common/include" --include_path="/home/matteo/ti/C2000Ware_1_00_00_00_Software/device_support/f2837xs/headers/include" --define=CPU1 --define=_LAUNCHXL_F28377S --define=_FLASH -g --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="F2837xS_usDelay.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '


