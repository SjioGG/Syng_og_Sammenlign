# Syng_og_Sammenlign
This project was conducted as part of the course: "Semester Project 3" @ Aarhus University.

The purpose of the project to make a karaoke system, where an input signal is correlated with a predefined signal and a score is caulculated. It consists of 2x RPis and a PSoC Unit and a Behringer UM2 Audio Interface. The main system runs on a RPi4, with RPiOS installed on it. This is where the Logic Unit and UI are present. The data is handeled by an RPiZero, which acts as a server. The purpose was to mimic a cloud enviorment, where the data is stored externally and pulled and pushed as needed by the main system. Therefore a ClientSocket class was made, which is an interface for the main unit to interact with the server and create easily accessible data for the main unit. The input signal is proccesesed on the PSoC and passed on to the main unit in form of a WAV file, which is then correlated on the RPi4. An intuitiv UI was also designed and implemented aswell.

To learn more and see our findings, refer to the PDF in the project repo, which is a through report of our process, development, responsibilities and findings in implementing the above described system.
