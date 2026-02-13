# Assignments 2026
## Assignment 1: The Bohr atom
This code is designed to take user inputs for atomic numbe (Z), initial energy level ($n_{initial}$), and final energy level ($n_{final}$) in the de-excitation of a Bohr atom to find the energy of the photon released in the transition. Photon energy can be calculated using  <br>
$$E = 13.6(\frac{1}{n_{final}^2}- \frac{1}{n_{initial}^2})Z^2$$ eV. <br>
This is also converted to frequency and wavelength using $E=hf$ and $c=f\lambda$. The user is then asked if they wish to repeat the programme. Energy can be expressed in units of eV and Joules.

By interpreting user inputs as one stream and converting to string stream, the first three inputs can be individually valiadted. New inputs are scrutinised repeatedly until a valid input is given. All inputs go through positive integer verification.

As the programme only accounts for de-excitation, it also checks that the final energy level is less than the initial energy level.

The highest atomic number is 118, which is the element Oganesson. Ergo, atoms of this atomic number indicate the cap for allowed values that the programme allows.

No A.I. assistance was used during the writing and testing of this programme.
