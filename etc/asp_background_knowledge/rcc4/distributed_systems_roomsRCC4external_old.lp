#program distributedSystemsRoomsExternal.
%%%%% Relations for PathPlanning

reachable(X, Y) :- reachable(Y, X), X!=Y.
reachable(X, Z) :- reachable(X, Y), reachable(Y,Z), X!=Y, Y!=Z, X!=Z. 
reachable(X, Y) :- partialOverlapping(X, Y), area(X), area(Y). 
reachable(X, Y) :- properPart(X, Y), room(X), area(Y).

%%%%% Discribes the rcc4 relations between the rooms in distributed systems

%%%%% rooms are part of an area

%%%%%%%%%%% externals

%%%% studentArea
#external partialOverlapping(studentArea, mainHallA).
#external disconnected(studentArea, mainHallA).

disconnected(studentArea, mainHallB).
disconnected(studentArea, workshop).
disconnected(studentArea, offices).
disconnected(studentArea, utility).
disconnected(studentArea, organization).

%%%% the studentArea consists of the rooms 1411 1411A and 1411C
#external properPart(r1411, studentArea).
#external disconnected(r1411, studentArea).
#external properPart(r1411A, studentArea).
#external disconnected(r1411A, studentArea).
#external properPart(r1411C, studentArea).
#external disconnected(r1411C, studentArea).

%%%% the rooms which are part of the studentArea are in relation to each other
#external partialOverlapping(r1411, r1411C).
#external disconnected(r1411, r1411C).
#external partialOverlapping(r1411A, r1411C).
#external disconnected(r1411A, r1411C).
disconnected(r1411, r1411A).

%%%% workshop
#external partialOverlapping(workshop, mainHallA).
#external disconnected(workshop, mainHallA).
disconnected(studentArea, mainHallB).
disconnected(workshop, studentArea).
disconnected(workshop, offices).
disconnected(workshop, utility).
disconnected(workshop, organization).

%%%% the workshop consists of the rooms 1410 1410A and 1410B
#external properPart(r1410, workshop).
#external disconnected(r1410, workshop).
#external properPart(r1410A, workshop).
#external disconnected(r1410A, workshop).
#external properPart(r1410B, workshop).
#external disconnected(r1410B, workshop).

%%%% the rooms which are part of the workshop are in relation to each other
#external partialOverlapping(r1410, r1410A).
#external disconnected(r1410, r1410A).
#external partialOverlapping(r1410, r1410B).
#external disconnected(r1410, r1410B).
disconnected(r1410A, r1410B).

%%%% offices
#external partialOverlapping(offices, mainHallA).
#external disconnected(offices, mainHallA).
#external partialOverlapping(offices, mainHallB).
#external disconnected(offices, mainHallB).
#external partialOverlapping(offices, utility).
#external disconnected(offices, utility).
disconnected(offices, workshop).
disconnected(offices, studentArea).
disconnected(offices, organization).

%%%% the offices consists of the rooms 1407 1408A 1408B 1408C 1406A 1406B 1406C
#external properPart(r1407, offices).
#external disconnected(r1407, offices).
#external properPart(r1408A, offices).
#external disconnected(r1408A, offices).
#external properPart(r1408B, offices).
#external disconnected(r1408B, offices).
#external properPart(r1408C, offices).
#external disconnected(r1408C, offices).
#external properPart(r1406A, offices).
#external disconnected(r1406A, offices).
#external properPart(r1406B, offices).
#external disconnected(r1406B, offices).
#external properPart(r1406C, offices).
#external disconnected(r1406C, offices).

%%%% the rooms which are part of the offices are in relation to each other
#external partialOverlapping(r1407, r1408A).
#external disconnected(r1407, r1408A).
#external partialOverlapping(r1407, r1408B).
#external disconnected(r1407, r1408B).
#external partialOverlapping(r1407, r1408C).
#external disconnected(r1407, r1408C).
#external partialOverlapping(r1407, r1406A).
#external disconnected(r1407, r1406A).
#external partialOverlapping(r1407, r1406B).
#external disconnected(r1407, r1406B).
#external partialOverlapping(r1407, r1406C).
#external disconnected(r1407, r1406C).
disconnected(r1408A, r1408B).
disconnected(r1408A, r1408C).
disconnected(r1408A, r1406A).
disconnected(r1408A, r1406B).
disconnected(r1408A, r1406C).
disconnected(r1408B, r1408C).
disconnected(r1408B, r1406A).
disconnected(r1408B, r1406B).
disconnected(r1408B, r1406C).
disconnected(r1408C, r1406A).
disconnected(r1408C, r1406B).
disconnected(r1408C, r1406C).
disconnected(r1406A, r1406B).
disconnected(r1406A, r1406C).
disconnected(r1406B, r1406C).

%%%% mainHallA only consists of room 1401A
#external partialOverlapping(mainHallA, studentArea).
#external disconnected(mainHallA, studentArea).
#external partialOverlapping(mainHallA, mainHallB).
#external disconnected(mainHallA, mainHallB).
#external partialOverlapping(mainHallA, workshop).
#external disconnected(mainHallA, workshop).
#external partialOverlapping(mainHallA, offices).
#external disconnected(mainHallA, offices).
disconnected(mainHallA, utility).
disconnected(mainHallA, organization).

equal(r1401A, mainHallA).

%%%% mainHallB only consists of 1401B
#external partialOverlapping(mainHallB, mainHallA).
#external disconnected(mainHallB, mainHallA).
#external partialOverlapping(mainHallB, offices).
#external disconnected(mainHallB, offices).
#external partialOverlapping(mainHallB, utility).
#external disconnected(mainHallB, utility).
#external partialOverlapping(mainHallB, organization).
#external disconnected(mainHallB, organization).
disconnected(mainHallB, studentArea).
disconnected(mainHallB, workshop).

equal(r1401B, mainHallB).

%%%% utility
#external partialOverlapping(utility, mainHallB).
#external disconnected(utility, mainHallB).
#external partialOverlapping(utility, organization).
#external disconnected(utility, organization).
#external partialOverlapping(utility, offices).
#external disconnected(utility, offices).
disconnected(utility, workshop).
disconnected(utility, studentArea).
disconnected(utility, mainHallA).

%%%% the utility area consists of the rooms 1405 1405A 1405B and 1403C
#external properPart(r1405, utility).
#external disconnected(r1405, utility).
#external properPart(r1405A, utility).
#external disconnected(r1405A, utility).
#external properPart(r1405B, utility).
#external disconnected(r1405B, utility).
#external properPart(r1403C, utility).
#external disconnected(r1403C, utility).

%%%% the rooms which are part of the utility area are in relation to each other
#external partialOverlapping(r1405, r1405A).
#external disconnected(r1405, r1405A).
#external partialOverlapping(r1405A, r1405B).
#external disconnected(r1405A, r1405B).
#external partialOverlapping(r1405A, r1403C).
#external disconnected(r1405A, r1403C).
disconnected(r1410A, r1410B).
disconnected(r1410A, r1410B).
disconnected(r1410A, r1410B).

%%%% organization
#external partialOverlapping(organization, mainHallB).
#external disconnected(organization, mainHallB).
#external partialOverlapping(organization, utility).
#external disconnected(organization, utility).
disconnected(organization, mainHallA).
disconnected(organization, workshop).
disconnected(organization, offices).
disconnected(organization, studentArea).

%%%% the organization area consists of the rooms 1403 1403A and 1403B
#external properPart(r1403, organization).
#external disconnected(r1403, organization).
#external properPart(r1403A, organization).
#external disconnected(r1403A, organization).
#external properPart(r1403B, organization).
#external disconnected(r1403B, organization).

%%%% the rooms which are part of the organization area are in relation to each other
#external partialOverlapping(r1403A, r1403B).
#external disconnected(r1403A, r1403B).
#external partialOverlapping(r1403B, r1403).
#external disconnected(r1403B, r1403).
disconnected(r1403A, r1403).

%%%%%%% relations between rooms and POIs

%%% 1411
properPart(studentLab1, r1411).
properPart(kicker, r1411).
properPart(studentLab2, r1411).
properPart(studentLabDoor1, r1411).

%%%% 1411C
properPart(floor1, r1411C).
properPart(studentLabDoor2, r1411C).
properPart(hiWiDoor1, r1411C).

%%%% 1411A
properPart(hiwiroom, r1411A).
properPart(hiWiDoor2, r1411A).

%%%% 1401A
properPart(floor1Door1, r1401A).
properPart(floor1Door2, r1401A).
properPart(floor1Door3, r1401A).
properPart(floor1Door4, r1401A).

%%%% 1401B
properPart(floor3Door1, r1401B).
properPart(floor3Door2, r1401B).
properPart(floor3Door3, r1401B).
properPart(floor3Door4, r1401B).

%%%% 1410
properPart(workShopDoor1, r1410).
properPart(workShopDoor2, r1410).

%%%% 1407
properPart(floor2Door1, r1407).
properPart(floor2Door2, r1407).
properPart(floor2Door3, r1407).
properPart(floor2Door4, r1407).
properPart(floor2Door5, r1407).
properPart(floor2Door6, r1407).
properPart(floor2Door7, r1407).
properPart(floor2Door8, r1407).
properPart(floor2Door9, r1407).

%%%% 1410A
properPart(workShopDoor3, r1410A).
properPart(workShopright, r1410A).

%%%% 1410B
properPart(workShopDoor4, r1410B).
properPart(workShopLeft, r1410B).

%%%% 1408A
properPart(room1408A, r1408A).

%%%% 1408B
properPart(room1408BFront, r1408B).
properPart(room1408BWindow, r1408B).

%%%% 1408C
properPart(room1408CFront, r1408C).
properPart(room1408CWindow, r1408C).

%%%% 1406A
properPart(room1406AFront, r1406A).
properPart(room1406AWindow, r1406A).

%%%% 1406B
properPart(room1406BFront, r1406B).
properPart(room1406BWindow, r1406B).

%%%% 1406C
properPart(room1406C, r1406C).

%%%% 1405B
properPart(kitchen, r1405B).

%%%% 1405A
properPart(floor4, r1405A).
properPart(floor4Door1, r1405A).
properPart(floor4Door2, r1405A).

%%%% 1405
properPart(meetingroom, r1405).

%%%% 1403C
properPart(copyroom, r1403C).
properPart(copyroomDoor1, r1403C).
properPart(copyroomDoor2, r1403C).

%%%% 1403A
properPart(secreteriatDoor1, r1403A).
properPart(secreteriatDoor2, r1403A).
properPart(secreteriatDoor3, r1403A).
properPart(secreteriat, r1403A).

%%%% 1403
properPart(room1403Door, r1403).
properPart(room1403, r1403).

%%%%% Areas
area(mainHallA).
area(mainHallB).
area(workshop).
area(offices).
area(utility).
area(organization).
area(studentArea).

%%%%% Rooms
room(r1411).
room(r1411A).
room(r1411C).
room(r1410).
room(r1410A).
room(r1410B).
room(r1407).
room(r1408A).
room(r1408B).
room(r1408C).
room(r1406A).
room(r1406B).
room(r1405).
room(r1405A).
room(r1405B).
room(r1403C).
room(r1403).
room(r1403A).
room(r1403B).

%%%%% POI
poi(studentLab1).
poi(kicker).
poi(studentLab2).
poi(studentLabDoor1).
poi(floor1).
poi(studentLabDoor2).
poi(hiWiDoor1).
poi(hiwiroom).
poi(hiWiDoor2).
poi(floor1Door1).
poi(floor1Door2).
poi(floor1Door3).
poi(floor1Door4).
poi(floor3Door1).
poi(floor3Door2).
poi(floor3Door3).
poi(floor3Door4).
poi(workShopDoor1).
poi(workShopDoor2).
poi(floor2Door1).
poi(floor2Door2).
poi(floor2Door3).
poi(floor2Door4).
poi(floor2Door5).
poi(floor2Door6).
poi(floor2Door7).
poi(floor2Door8).
poi(floor2Door9).
poi(workShopDoor3).
poi(workShopright).
poi(workShopDoor4).
poi(workShopLeft).
poi(room1408A).
poi(room1408BFront).
poi(room1408BWindow).
poi(room1408CFront).
poi(room1408CWindow).
poi(room1406AFront).
poi(room1406AWindow).
poi(room1406BFront).
poi(room1406BWindow).
poi(room1406C).
poi(kitchen).
poi(floor4).
poi(floor4Door1).
poi(floor4Door2).
poi(meetingroom).
poi(copyroom).
poi(copyroomDoor1).
poi(copyroomDoor2).
poi(secreteriatDoor1).
poi(secreteriatDoor2).
poi(secreteriatDoor3).
poi(secreteriat).
poi(room1403Door).
poi(room1403).
