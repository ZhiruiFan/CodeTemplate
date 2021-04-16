#include <petsc.h>
#include <initializer_list>
PetscErrorCode main(int argc, char** argv)
{
    //      Define variables
    PetscInt rank, size, Dim = 20;
    Vec Vars;
    PetscInt StartVec, EndVec, StartCal, EndCal;
    PetscInt LocalVec, LocalCal;
    PetscInt base, rest;

    //      Initialize the MPI environment
    PetscInitialize(&argc, &argv, NULL, "\t[MAIN] THE INVERSE MOTION ANALYSIS AND OPTIMIZATION.\n");
    MPI_Comm_rank(PETSC_COMM_WORLD, &rank);
    MPI_Comm_size(PETSC_COMM_WORLD, &size);

    //      Create the vector variables
    VecCreateMPI(PETSC_COMM_WORLD, PETSC_DECIDE, Dim, &Vars);
    VecGetLocalSize(Vars, &LocalVec);
    VecGetOwnershipRange(Vars, &StartVec, &EndVec);

    //      Calculate the local size, as well the start and end index of Vec vars
    base = Dim / size; rest = Dim % size;
    if (0 == rest){
        LocalCal = base;
        StartCal = base * rank;
        EndCal = StartCal + LocalCal;
    }else{
        if (rank < rest){
            LocalCal = base + 1;
            StartCal = (base + 1) * rank;
            EndCal = StartCal + LocalCal;
        }else{
            LocalCal = base;
            StartCal = (base + 1) * rest + (rank - rest) * base;
            EndCal = StartCal + LocalCal;
        }
    }

    //      Print information
    PetscPrintf(PETSC_COMM_SELF, "%s\t%d, %d, %d, %d\n", "Auto assigned by PETSC   :", rank, StartVec, EndVec, LocalVec);
    PetscPrintf(PETSC_COMM_SELF, "%s\t%d, %d, %d, %d\n", "Auto assigned by our code:", rank, StartCal, EndCal, LocalCal);

    //      Finalization
    PetscFinalize();
}