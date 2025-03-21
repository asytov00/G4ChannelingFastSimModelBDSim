# G4ChannelingFastSimModelBDSim [1]
A bent crystal as a BDSim accelerator usercomponent to simulate crystal-based extraction or crystal-based collimation. 
This model exploits G4ChannelingFastSimModel [2,3] (Geant4 v11.2.0 and higher) which is capable to simulate the physics of charged particles interaction with oriented crystals, in particular physics of channeling, channeling radiation/coherent bremsstrahlung and coherent pair production.
https://geant4-userdoc.web.cern.ch/UsersGuides/PhysicsReferenceManual/html/solidstate/channeling/channeling_fastsim.html

In order to use this model one should prepare an accelerator setup through BDSim macro files (see BDSim help http://www.pp.rhul.ac.uk/bdsim/manual/),
in which one should add a bent crystal component in the following way (... should be replaced by values): 

CR1: usercomponent, userTypeName="crystaldeflector", l=..., xsize=...*cm, ysize=...*cm, materialThickness=...*mm, offsetX=...*cm, offsetY=...*mm, axisX=..., axisY = ..., axisZ = ..., horizontalWidth=...*cm,  material="G4_Si", vacuumMaterial="vacuum", userParameters="crystalRegion:crystal1 crystalBendingAngle:... crystalLattice:(111) colour:decapole radiationModel:false";

CR1 is the component’s name.
• userTypeName identifies the component type as ”crystaldeflector”.\\
• l, xsize, ysize, and materialThickness define the dimensions and thickness of the crystal in the G4Box.
• offsetX, offsetY, and axisX, axisY, axisZ define the component’s position and orientation in the beamline.
• horizontalWidth defines the vacuum space of the component around the crystal.
• material specifies the crystal material (e.g., silicon), and vacuumMaterial sets the surrounding vacuum.
• userParameters contains specific parameters for the crystal, such as the G4Region name for crystal channeling, bending angle, crystallographic orientation, visualization color, and radiation model activation.

The radiation model simulating the radiation energy losses is G4BaierKatkov using Baier-Katkov method [4].

[1] A. Sytov et al. https://arxiv.org/abs/2412.10715

[2] A. Sytov et al. Journal of the Korean Physical Society 83, 132-139, (2023) DOI: https://doi.org/10.1007/s40042-023-00834-6

[3] R. Negrello,..., A. Sytov. Nuclear Instruments and Methods in Physics Research, Section A 1074, 170277 (2025) DOI: https://doi.org/10.1016/j.nima.2025.170412 

[4] V. N. Baier, V. M. Katkov, and V. M. Strakhovenko, Electromagnetic Processes at High Energies in Oriented Single Crystals (World Scientific, Singapore, 1998).

G4ChannelingFastSimModelBDSim has been developed by Alexei Sytov within European Commission H2020-MSCA-IF-2020-GF TRILLION, GA. 101032975.
