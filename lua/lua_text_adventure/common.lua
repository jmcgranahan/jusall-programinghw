--COMMON SCRIPT FILE

function round(num, places)
  local mult = 10^(places or 0)
  return math.floor(num * mult + 0.5) / mult
end

function gen_random(max)
	local temp = math.mod((42 * math.random() + 29573), 139968)
	local ret = math.mod( ((100 * temp)/139968) * 1000000, max)
	return round(ret + 0.5)
end

function random_range(min,max)
	return gen_random(max-min) + min
end

function GetInput()
	return io.stdin:read("*l")
end

function Timer()
	return os.clock() * 1000
end

start_time = 0
function Stopwatch(ms)
	if Timer() > start_time + ms then
		start_time = Timer()
		return true
	else
		return false
	end
end

function pause(ms)
	while Stopwatch(ms) == false do
		--waiting...
	end
end

--print("Common code loaded")

math.randomseed( os.time() )

