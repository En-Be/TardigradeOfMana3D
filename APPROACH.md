# APPROACH

## Session 01

Minutes: 120

DONE
- Set up project
- Added input, bindings, and functions for movement and look

---

## Session 02

Minutes: 30

DONE
- Added a camera on a spring arm to MyPlayerCharacter
- Changed the animation mode to use an animation sequence asset

---

## Session 03

Minutes: 70 

DONE
- Created a blend space, added idle/walk/jog
- Used inverse transform vector to check local movement and pass it as an angle to the blend space

---

## Session 04

Minutes: 65

DONE
- Calculated walk speeds and changed axis scales on blend space
- Added a gun C++ class and a rifle blueprint inheriting from it
- Added root and mesh uproperties
- Added a gun class uproperty on player character blueprint
- Set gun class on player character blueprint
- Tell world to spawn gun actor
- Hid weapon on the mesh via c++
- Added a socket on the hidden bone
- Attached the spawned gun to the socket
- Set the gun's parent to the player character

## Session 05

Minutes: 30

DONE
- Declared a PullTrigger function on gun
- Defined it with a log message for now
- Shoot function on player character that calls gun's pulltrigger
- Added a muzzleflash uproperty
- Muzzleflash particle emitter set in rifle blueprint
- Muzzle flash spawned in pulltrigger