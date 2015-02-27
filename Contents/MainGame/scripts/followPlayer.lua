acceleration_init = 1
circle_radius = 10

function ReceiveMessage(msg)

end


function Update(obj,dt)
    acc = obj["acc"]
    acc.x = 0 ; acc.y = 0
    circle = {center = {x = obj.pos.x + 16, y = obj.pos.y + 16},radius = circle_radius }


-- BUG Essa colisão não funciona
    if isCollidingRC(player.pos,circle) then
        print("Colidindo")
        print(circle.center.x)
        print(circle.center.y)
        print(player.rect.x)
        print(player.rect.y)

        acc.x = -1
    end



end
