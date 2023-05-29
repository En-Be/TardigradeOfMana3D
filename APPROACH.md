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

DONE
- Created a UI widget
- Added UMG dependency to build file
- Added a lose screen class to myplayercontroller.h
- Assigned the class in the playercontroller blueprint
- Added the widget to viewport when player dies

---

## Session 19

Minutes: 40

DONE
- Iterate over actors in the level to see if player has lost
- Iterate over actors to see if all pawns are dead
- Display win widget when all AI controllers are dead

---

## Session 20

Minutes: 30

DONE
- Refactored gun::pulltrigger to seperate methods
- Spawning a shoot sound attached to the gun
- Spawning an impact sound at the hit location

## Session 21

Minutes: 20

DONE
- Swapped individual sound waves for sound cues
- Random sound selection and modulation in cues
- Made a default attenuation settings and set it in shot and impact cues

## Session 22

Minutes: 40 

DONE
- Created a HUD widget which spawns at play
- Remove HUD from display when game over
- Added a progress bar to hud bp
- Added a c++ method to get player character health percent
- Bind the progress bar percent to a graph
- In the graph, cast the owner as pawn to then call the health percent method

## Session 23

Minutes: 27

DONE
- Added aim offset to animgraph
- Set pitch in eventgraph
- Changed AI aim to look for player object instead of locations

---

## Session 24

Minutes: 30

DONE
- Added a 'jump' input mapping
- Bound the input action to a call to 'Jump' in the character c++
- Added a state machine in the animgraph
- Added 'grounded' and 'airborn' states
- Added an airborn animation
- Added a boolean that is the condition for changing states
- Added .pdb files to gitignore

## Session 25

Minutes: 27

DONE
- Used 'is falling' from the character class to set the 'is airborn' boolean in the animgraph
- Added a death state machine with alive and dead states
- Added ambient music

---

## Session 26

Minutes: 30

TODO
- Enemies start at low health and can't shoot
- Shooting enemies increases their health
- Full health enemies stop following player

DONE
- Changed guns to do negative damage
- Set character health to start at maxhealth/10
- Added a selector node to the enemy AI

## Session 27

Minutes: 120

TODO
- Make selector check if ai is at full health
- Move to startlocation if yes
- Existing behaviour if no

DONE
- Added a ufunction 'is healed' to ai controller which call to player character
- Added a ufunction 'is healed' to player character which checks health against max health
- Added a selector in ai behaviour tree which checks 'is healed' to choose existing behaviour or move to start
- Added a BTService 'AI is healed'
- Trying to the the owner controller but 'GetPawn()' is apparently undefined. Asking for help

## Session 28

Minutes: 75

TODO
- Clamp the health of pawns to not go over max

DONE
- Health is clamped
- Commented out the bt service, set the 'AIishealed' boolean in blueprint instead
- AI behaviour not as expected

---

## Session 29

Minutes: 25

TODO
- Fix behaviour tree

DONE
- Set the 'observer aborts' option to 'both' on new blackboard condition


## Session 30

Minutes: 25

TODO
- Sculpt eyeball creature

DONE
- Sculpt eyeball creature
![](wip/screenshots/wip_04.jpg)


## Session 31

Minutes: 38

TODO
- Retopo creature

DONE
- Retopo creature
![](wip/screenshots/wip_05.jpg)

---

## Session 32

Minutes: 90 mins

TODO
- UV creature
- Bake AO

DONE
- Mark seams
- unwrap
- position islands
- painted base colour
- blender erased texture?!?!?
- repainted base colour

---

## Session 33

Minutes: 27

TODO
- Retexture the pod creature with gradients

DONE
- Retexture the pod creature with gradients
- Edited specular on eye and body
![](wip/screenshots/wip_06.jpg)


## Session 34

Minutes: 42 

TODO
- Rig pod creature

DONE
- Made a rig
- parented body with auto weights
- removed weight from eye bone
- edited weights for eyelids
- parented eyeball to eye bone

![](wip/screenshots/wip_07.jpg)

## Session 35

Minutes: 60

TODO
- clean mesh
- idle animation

DONE
- clean mesh
- idle animation
![](wip/screenshots/wip_08.gif)
- there are some strange shading artifacts on the mesh

---

## Session 36

Minutes: 30

TODO
- Aggro animation
- Solve artifacts

DONE
- Started making an erratic animation
- Realised would be better to just use noise curves on position and scale
- Baked noise modifiers to keyframes
![](wip/screenshots/wip_10.gif)

---

## Session 37

Minutes: 25

TODO
- Attack animation

DONE
- Added rotation noise to aggro animation
![](wip/screenshots/wip_12.gif)
- Attack animation
![](wip/screenshots/wip_11.gif)

## Session 38 

Minutes: 30

TODO
- New unreal level
- Export pod creature from blender
- Import pod creature to Unreal
- Create new pod creature blueprint

DONE
- Followed these instruction on exporting:
https://www.immersivelimit.com/tutorials/export-animations-from-blender-to-unreal-engine
- Moved existing content to 'temp' folder
- Duplicated level, renamed 'demo', deleted assets except sky etc
- Added a cylinder for temp floor
- Imported pod creature to new 'characters' folder
- Pod creature was tiny, reset blender units scale to 1
- Set an idle animation, playing fine

## Session 39

Minutes: 35

TODO
- Export+import pod texture
- New pod creature blueprints

DONE
- png exported
- png won't import
- opened in krita and exported
- png imported to unreal
- png applied to material
- is too shiny, will need to set it in editor or create pbr maps in blender
- pod is too low off the floor, will need to adjust animations
- attack animation is too long, needs to be snappier
- mesh is collapsing, could be a weighting problem

---

## Session 40

Minutes: 30

TODO
- Set material properties in engine OR generate PBR maps in blender

DONE
- Used 'constant' nodes to plug a value into the specular and metallic parameters of the materials
- Increased the intensity of the scene direction light

## Session 41

Minutes: 180 minutes

TODO
- Weight the eyeball manually
- Re-export and import

DONE
- Weight the eyeball manually
- Re-export and import
- Still not deforming properly
- Tried different import and export options
- Tried normalising the weights
- Posted in slack asking for help

---

## Session 42

Minutes: 80

TODO
- Try again to fix mesh deformation glitch

DONE
- Vertex groups and bone weight paints aren't the same, should they be?
- Removed armature modifier, deleted vertex groups
- Added new automatic weights
- After lots omre trial and error, going to try an add-on that creates game-ready rigs

---

## Session 43

Minutes: 60

TODO
- Download and install addon
- Download mannequin model
- Make test rigify rig
- Generate game-ready rig
- Export and import to Unreal

DONE
- Download and install addon
- Download mannequin model
- Make test rigify rig
- Generate game-ready rig
- Export and import to Unreal
- Seems to be working
![](wip/screenshots/wip_17.gif)


## Session 44

Minutes: 115

TODO
- Test pod creature
- Addon action baking
- Build new rig for podcreature following P2Design course

DONE
- Tried generating rig with addon, doesn't fix issue
- Recreated a simpler rig with a flat bone heirarchy and 'child of' constraints where appropriate
- Works
![](wip/screenshots/wip_18.gif)
- Can this be done without a proxy rig?
- A proxy needs to be created, but it doesn't need the meshes to be bound to it, or have the actions baked
- Tested the mannequin (rigify), it does need binding and baking
- A way to edit animations without changing the parenting would be useful

--- 

## Session 45

Minutes: 45

TODO
- Reanimate pod creature
    - Idle
    - Agressive
    - Attack

DONE
- Reanimated idle loop
- Baked and imported to Unreal
- Works

## Session 46

Minutes: 20

TODO
- Reanimate pod creature
    - Agressive
    - Attack

DONE
- Reanimate pod creature
    - Agressive
    - Attack
- Imported to unreal
- Remade body material in unreal

## Session 47

Minutes: 100

TODO
- Duplicate enemy blueprints
- Adapt enemy blueprints to use pod creature
- Change game win state to heal all rather than kill all

DONE
- Made a PodCreature class to create BP from
- Copied relevent functions from playercharacter class
- Adapted the AIController and animgraph partway, very confused, need to step back

---

## Session 48

Minutes: 180

DONE
- Implemented pod creature except for it's attack

---

## Session 49

Minutes: 30 

TODO
- BTTasks for pod creature attack and move
- Switch pod creature animation state for attack/move
- BTTask 'attack' sets a bool which is used to update state machine
- Animgraph notify works


## Session 50

Minutes: 30

TODO
- BTTask for patrol state
- Collider for attack damage event

DONE
- BTTask for patrol state
- Added a collider at attack impact position on pod creature
- Added begin and end overlap events on the pod creature, which flip a bool

## Session 51

Minutes: 50

TODO
- Check bool at hit notify to trigger takedamage

DONE
- Player takes damage

## Session 52

Minutes: 30

TODO
- Fix lose and win states

DONE
- Changed AI controller to check for dead pod creatures
- Lose state working
- Added win state to all pawns healed
- Win state working

## Session 53

Minutes: 45 

TODO
- Make win state work with multiple AIs
- Make AIs stop attacking if player dead
- Random AI patrol movement
- Change pod creature iris colour

DONE
- Changed AI controller to check for podcreatures instead of players
- Win state working with multiple creatures
- Looking for ways to make patrol random, could be long, might be best to move on to implementing custom player character instead
- Tried changing iris colour from ABP, might try again from BP

---

## Session 54

Minutes: 480

DONE
- Player character created and rigged

---

## Session 55

Minutes: 300

DONE
- Player character textured and animated

---

## Session 56

Minutes: 70

TODO
- Export player to engine
- Implement skeletal mesh

DONE
- Generated game ready rig
- Exported
- Errors on import: 
    - zero scaling of bones breaks animation
    - eye normals inside out
- Recalculated eye normals, fixed
- Baked textures into one, applied to material
- Set specular and roughness on eye material
- Set bone scaling to be 0.001 at relevant keyframes. Not playing back as intended, might need to make materials go invisible instead
- Made new animation blueprint based on player skeleton, copied event graph from temp character, added variables
- Made a blendspace with new player run and idle animations, added to animation blueprint
- Character animations play when idle and running
- Need animation for strafing + running backwards + jumping

---

## Session 57

Minutes: 45

TODO
- Animations:
    - Strafing x 2
    - Run backwards
- Toggle off jump

DONE
- Animations:
    - Strafing x 2
    - Run backwards
    - Baked to deform mesh

## Session 58

Minutes 45

TODO
- Toggle off jump
- Implement animations in engine

DONE
- Imported fbx in a different folder to get import menu
- Deselected import mesh, just animations imported
- Moved animations to proper folder
- Adjusted scales on blendspace, added new animations
- Commented out the jump listener in c++
- Forgot to add the death animation, added
- Kept playing death initially
- Added a transition rule for back to alive, working

## Session 59

Minutes: 75

TODO
- Player aim angle
- Make gun socket and hide gun
- Stop pod attacking when player dead
- Add a menu level

DONE
- Made gun invisible
- Added a socket on player character
- Gun snaps to socket
- Basic particle effects on shot and hit
- Tried setting a blackboard variable via c++ to stop enemy attacking, can't get behaviour tree to work.
- Was on the wrong blackboard! Fixed.

--- 

## Session 76

Minutes: 30

TODO
- Use blueprint to check for all healed
- Remove current allhealed behaviour
- Open gate on allhealed

DONE
- Recalculated world collision mesh and added a (hidden) plane at floot level
- Added a boolean to player controller that is set to true when all healed
- Turned off win hud
- Turned off reset timer
- Door bp checking player controller for bool
- Door destroys self when bool is true

## Session 77

Minutes: 40

TODO
- Add end zone inside building
- Display win state and timer
- Disable player input and hud on menu

DONE
- Add end zone inside building
- Display win state and timer
- Disable player input and hud on menu
- Changed HUD colours
- Stopped hud disappearing on all healed