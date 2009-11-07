--[[

	TEXT ADVENTURE GAME PROJECT

]]--

dofile("common.lua")
gameover = false

-- GAME LEVEL STUFF

rooms = { }
rooms[1] = {
  name = "COURTYARD",
  desc = "You are in a cobblestone courtyard in front of a huge castle.",
  north = 2,
  east = 0,
  south = 0,
  west = 0,
  monster = 0
}
rooms[2] = {
  name = "CASTLE COMMONS",
  desc = "You are inside the entryway to the castle. You see a vendor selling arms.",
  north = 3,
  east = 0,
  south = 1,
  west = 0,
  monster = 1
}
rooms[3] = {
  name = "KEEP",
  desc = "You have entered the castle's inner keep. A stairway leads down to the east.",
  north = 0,
  east = 4,
  south = 2,
  west = 0,
  monster = 2
}
rooms[4] = {
  name = "DUNGEON",
  desc = "You see many gated dungeon cells and torture devices. You hear moaning and weeping coming from one of the dark cells.",
  north = 0,
  east = 0,
  south = 0,
  west = 3,
  monster = 3
}
room = 1
firstvisit = true


function PrintRoom()
  if firstvisit == false then return end

	print("")
  print(rooms[room].name)
  print(rooms[room].desc)
  if (rooms[room].monster > 0) then
	m = rooms[room].monster
	PrintMonster(monsters[m])
  end
	print("")
  rstr = "Paths: "
  if (rooms[room].north > 0) then rstr = rstr .. "North" end
  if (rooms[room].east > 0) then rstr = rstr .. " East" end
  if (rooms[room].south > 0) then rstr = rstr .. " South" end
  if (rooms[room].west > 0) then rstr = rstr .. " West" end  
  print(rstr)


  firstvisit = false
  print("")
end

function GoNorth()
  if (rooms[room].north > 0) then
    room = rooms[room].north
    print("You walk North")
    firstvisit = true
    PrintRoom()
  else
    print("You cannot go that way.")
  end
end

function GoEast()
  if (rooms[room].east > 0) then
    room = rooms[room].east
    print("You walk East")
    firstvisit = true
    PrintRoom()
  else
    print("You cannot go that way.")
  end
end

function GoSouth()
  if (rooms[room].south > 0) then
    room = rooms[room].south
    print("You walk South")
    firstvisit = true
    PrintRoom()
  else
    print("You cannot go that way.")
  end
end

function GoWest()
  if (rooms[room].west > 0) then
    room = rooms[room].west
    print("You walk West")
    firstvisit = true
    PrintRoom()
  else
    print("You cannot go that way.")
  end
end


-- ITEMS AND STUFF
items = { }
items[1] = {
  name = "Rusty Dagger",
  attack = 1,
  defend = 0
}
items[2] = {
  name = "Plain Clothes",
  attack = 0,
  defend = 1
}

-- MONSTER STUFF

monsters = { }
monsters[1] = {
	name = "Kobold",
	health = 20,
	attack = 2,
	defend = 2
}

function PrintMonster(m)
	print("")
  print("You see a " .. m.name .. ".")
	if m.health < 20 then
		print("It looks really weak.")
	else
		print("Oh crap, you are screwed.")
	end
end


-- PLAYER STUFF

function DoRandomPlayer(c)
  -- REPLACE WITH RANDOM VALUES
  char = {
    name = "Player",
    class = "Warrior",
    age = 23,
    level = 1,
    exp = 0,
    health = 100,
    str = 18,
    dex = 19,
    int = 16,
    con = 14,
    cha = 17,
    attack = 2,
    defend = 2,
    weapon = 1,
    armor = 2
  }

  print("Enter your name: ")
  char.name = GetInput()  

  return char

end

function GetPlayerAttack()
	return player.attack + items[player.weapon].attack
end

function GetPlayerDefend()
	return player.defend + items[player.armor].defend
end

function PrintCharacter(c)
  print("Name: " .. c.name)
  print("Age: " .. c.age)
  print("Level: " .. c.level)
  print("Exp: " .. c.exp)
  print("Stats: STR DEX INT CON CHA")
  s = "        " .. c.str .. "  "
  s = s .. c.dex .. "  "
  s = s .. c.int .. "  "
  s = s .. c.con .. "  "
  s = s .. c.cha
  print(s)
  print("Health: " .. c.health)
  print("Weapon: " .. items[c.weapon].name)
  print("Armor: " .. items[c.armor].name)
  attack = GetPlayerAttack()
  print("ATT: " .. attack)
  defend = GetPlayerDefend()
  print("DEF: " .. defend)
  print("")
end


-- COMBAT 

function Attack()
	if (rooms[room].monster == 0) then 
		print("  Attack WHAT, exactly?")
		return 
	end
	
	pause(random_range(2000,4000))

	m = rooms[room].monster

	--player attacks monster
	attack = random_range(1, GetPlayerAttack())
	print("")
	print("  You hit the " .. monsters[m].name .. " for " .. attack .. " damage.")
	monsters[m].health = monsters[m].health - attack
	if monsters[m].health <= 0 then
		pause(random_range(2000,3000))
		print("  You killed the " .. monsters[m].name .. ".")
		rooms[room].monster = 0
	end

	--monster attacks player
	if monsters[m].health > 0 then
		attack = random_range(1,monsters[m].attack)
		print("")
		print("  The " .. monsters[m].name .. " hit you for " .. attack .. " damage.")
		player.health = player.health - attack
		if player.health <= 0 then
			pause(random_range(2000,3000))
			print("  YOU HAVE DIED!!!")
		end
	end
	
	print("")
	firstvisit = true
	PrintRoom()
end



-- INPUT PARSER

function ParseInput()
  if input == "quit" or input=="q" then gameover = true end
  if input == "stats" then PrintCharacter(player) end
  if input == "help" then
    print("Commands: quit,stats,north,south,east,west,attack")
  end
  if input == "north" then GoNorth() end
  if input == "east" then GoEast() end
  if input == "south" then GoSouth() end
  if input == "west" then GoWest() end
  if input == "look" then 
	firstvisit = true
	PrintRoom() 
  end
  if input == "attack" then Attack() end

  print("")
end



-- START GAME

print "ADVENTURE GAME"
print ""


-- CREATE PLAYER CHARACTER

player = DoRandomPlayer()
PrintCharacter(player)


-- GAME LOOP
repeat

  PrintRoom()

  print(">>>")
  input = GetInput()
  ParseInput()

until gameover

print("Fare thee well, brave one.")

