## Dataset for the study "An Empirical Study of Test Generation Techniques on Property Checking for Controller Software"

This dataset presents the experimental results and detailed information about our subject programs.

A set of benchmarks is available [here](https://ora.ox.ac.uk/objects/uuid:f1b19a1a-f3c1-4eca-8755-73706c0af383). From this benchmark, we selected seven programs based on the criteria mentioned in our paper. The selected programs are listed below:

| Prog. | Name | 
|-------|----------|
| P1    |BangBangControlUsingTemporalLogicExample (InOn)|
| P2    |MealyVendingMachineExample|
| P3    |ModelingAnIntersectionOfTwo1wayStreetsUsingStateflowExample (InRed)|      
| P4    |StateTransitionMatrixViewForStateTransitionTableExample|   
| P5    |SequenceRecognitionUsingMealyAndMooreChartExample|     
| P6    |ModelingASecuritySystemExample (InAlarm/InOn)|        
| P7    |ModelingACdPlayerradioUsingEnumeratedDataTypeExample (CdPlayerModeManager/InOn)|


The [exp\_result](exp_result) folder contains experimental results for the four test generation techniques (CROWN, LTL-Fuzzer, AFL++, AFL) across seven programs (P1-P7). Each program folder includes:

- `crown_violation_num.csv`/`ltlfuzz_violation_num.csv`/`aflpp_violation_num.csv`/`afl_violation_num.csv`: The detection of property violations for each mutant-property pair over 10 repetitions (**Yes/No**: a technique could/could not detect a property violation in a repetition; **Total column**: the total number of times a technique could detect a property violation over 10 repetitions).
- `crown_detection_time.csv`/`ltlfuzz_detection_time.csv`/`aflpp_detection_time.csv`/`afl_detection_time.csv`: The detection time for each mutant-property pair over 10 repetitions. The average detection time is shown in the last column.
- `summary.xlsx`: A summary of the results, including violation detection ratios, and detection times.

The [program\_information](program_information) folder contains detailed information about the programs. Each program folder includes:

- harness: the driver including mutants and properties for testing.
- model_package: model/ contains controller programs, and common/ contains their dependencies.
- mutant: mutants generated from the original controller programs by applying five mutation operators.
- spec: properties generated for each program through active-learning.

