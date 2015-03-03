acceleration_init = 1
circle_radius = 180



function getVectorToPlayer(player,obj)
    r = {}
    r.x = player.x - obj.x
    r.y = player.y - obj.y
    r.x = r.x/math.abs(r.x)
    r.y = r.y/math.abs(r.y)
    return r
end

function ReceiveMessage(msg)

end


function Update(obj,dt)
    acc = obj["acc"]
    acc.x = 0 ; acc.y = 0
    circle = {center = {x = obj.pos.x + 16, y = obj.pos.y + 16},radius = circle_radius }


-- Se colidir
    if isCollidingRC(player.pos,circle) then
        obj["acc"] = getVectorToPlayer(player["pos"],obj["pos"])
    end



end
