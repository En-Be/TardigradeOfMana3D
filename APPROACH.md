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

---

## Session 05

Minutes: 30

DONE
- Declared a PullTrigger function on gun
- Defined it with a log message for now
- Shoot function on player character that calls gun's pulltrigger
- Added a muzzleflash uproperty
- Muzzleflash particle emitter set in rifle blueprint
- Muzzle flash spawned in pulltrigger

---

## Session 06

Minutes: 35

DONE
- Initialised git repo. Added asste packs to gitignore because will be stripping them out
- Pushed initial commit to github
- Drawing a debug helper at camera view when trigger is pulled
- Added bullet collision trace channel, adjusted presets

---

## Session 07

Minutes: 25 

DONE
- Used a linetracesingle by channel to detect a hit, display a debug marker if true

---

## Session 08

Minutes: 35

DONE
- Impact particle effect emitted at point hit

---

## Session 09

Minutes: 18

DONE
- Override the take damage method
- Log remaining health to console

---

## Session 10

Minutes: 35

DONE
- Blending animation poses by bool IsDead
- Declared and defined IsDead in c++, returns health less or equal to 0
- In blueprints, pawn is cast as a MyPlayerCharacter, gets it's IsDead, sets the BP IsDead for the animGraph to use
- Created a MyShooterAIController based on AIController
- Created a Blueprint based on MyShooterAIController
- Set the BP as the default on the BP_MyPlayerCharacter

---

## Session 11

Minutes: 30

DONE
- On ai controller, SetFocus is used in BeginPlay to tell the bots who to aim at
- Created a navmeshboundsvolume
- Expanded the volume to cover the map
- On ai controller, added MoveToActor to Tick

---

## Session 12

Minutes: 45 

DONE
- Conditional for if bot can see player
- Bot stops moving if can't see player
- Created a blackboard and behaviortree
- Running behaviortree instead of conditional
- Added a player location key to blackboard
- Added a move and wait sequence to behaviortree

---

## Session 13

Minutes: 35

DONE
- Changed behaviour tree to use a selector that checks if player is visible
- If player is not visible, enemy walks to last know player location
- Player location is cleared in c++ when not in lineofsight
- Added a clearblackboardvalue c++ class
- Included a necessary module in the build file
- Added the new node to the blackboard tree

---

## Session 14

Minutes: 60

DONE
- New node gets owner's blackboard component and clears selected key
- New node for shooting
- Shoot casts the owner as a myplayercharacter
- Calls the myplayercharacter shoot
- Behaviourtree has a shoot and wait loop sequence to prevent shooting evey frame

---

## Session 15

Minutes: 30

DONE
- Added service nodes for checking player location
- Behavior created in tree nodes rather than plain text

---

## Session 16

Minutes: 30

DONE
- Added collision query parameters so the linetrace knows what to ignore when shooting
- When player or enemy is dead, their controller is detached and their collider is disabled
- Set a game mode BP that knows when a pawn is killed

---

## Session 17

Minutes: 20

DONE
- Created a player controller based on player controller
- set a blueprint class based on the player controller as the gamemode default
- Added a function on the player controller which overrides gamehasended with a 5 second restart timer

--- 

## Session 18

Minutes: 20

TODO
- Created a UI widget
- Added UMG dependency to build file
- Added a lose screen class to myplayercontroller.h
- Assigned the class in the playercontroller blueprint
- Added the widget to viewport when player dies
