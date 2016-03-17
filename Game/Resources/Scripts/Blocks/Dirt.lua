



function IsSolid(block)
	return true
end


-- Load stuff for the block
function AddVertexData(block, model)
	local dimension = block:GetChunk():GetDimension()
	
	local y = block:GetY()
	local ax = block:GetAbsX()
	local az = block:GetAbsZ()
	
	
	local tx = 2
	local ty = 0
	local tl = BlockTexture.GetTexCoord(tx + 0.05, ty + 0.05)
	local br = BlockTexture.GetTexCoord(tx + 0.95, ty + 0.95)
	
    
    -- Pos Y
    if ( not dimension:IsSolidBlock(ax, y + 1, az) ) then
        model:AddVertex(Vertex(FVec3(ax + 0, y + 1, az + 0), FVec3(0, 1, 0), FVec2(br.x, br.y)))
        model:AddVertex(Vertex(FVec3(ax + 0, y + 1, az + 1), FVec3(0, 1, 0), FVec2(br.x, tl.y)))
        model:AddVertex(Vertex(FVec3(ax + 1, y + 1, az + 1), FVec3(0, 1, 0), FVec2(tl.x, tl.y)))
        
        model:AddVertex(Vertex(FVec3(ax + 0, y + 1, az + 0), FVec3(0, 1, 0), FVec2(br.x, br.y)))
        model:AddVertex(Vertex(FVec3(ax + 1, y + 1, az + 1), FVec3(0, 1, 0), FVec2(tl.x, tl.y)))
        model:AddVertex(Vertex(FVec3(ax + 1, y + 1, az + 0), FVec3(0, 1, 0), FVec2(tl.x, br.y)))
    end
    
    -- Neg Y
    if ( not dimension:IsSolidBlock(ax, y - 1, az) ) then
        model:AddVertex(Vertex(FVec3(ax + 0, y + 0, az + 1), FVec3(0, -1, 0), FVec2(tl.x, br.y)))
        model:AddVertex(Vertex(FVec3(ax + 0, y + 0, az + 0), FVec3(0, -1, 0), FVec2(br.x, br.y)))
        model:AddVertex(Vertex(FVec3(ax + 1, y + 0, az + 0), FVec3(0, -1, 0), FVec2(br.x, tl.y)))
        
        model:AddVertex(Vertex(FVec3(ax + 0, y + 0, az + 1), FVec3(0, -1, 0), FVec2(tl.x, br.y)))
        model:AddVertex(Vertex(FVec3(ax + 1, y + 0, az + 0), FVec3(0, -1, 0), FVec2(br.x, tl.y)))
        model:AddVertex(Vertex(FVec3(ax + 1, y + 0, az + 1), FVec3(0, -1, 0), FVec2(tl.x, tl.y)))
    end
    
    -- Neg X
    if ( not dimension:IsSolidBlock(ax - 1, y, az) ) then
        model:AddVertex(Vertex(FVec3(ax + 0, y + 0, az + 0), FVec3(-1, 0, 0), FVec2(br.x, br.x)))
        model:AddVertex(Vertex(FVec3(ax + 0, y + 0, az + 1), FVec3(-1, 0, 0), FVec2(tl.x, br.x)))
        model:AddVertex(Vertex(FVec3(ax + 0, y + 1, az + 1), FVec3(-1, 0, 0), FVec2(tl.x, tl.x)))
        
        model:AddVertex(Vertex(FVec3(ax + 0, y + 0, az + 0), FVec3(-1, 0, 0), FVec2(tl.x, br.y)))
        model:AddVertex(Vertex(FVec3(ax + 0, y + 1, az + 1), FVec3(-1, 0, 0), FVec2(br.x, tl.y)))
        model:AddVertex(Vertex(FVec3(ax + 0, y + 1, az + 0), FVec3(-1, 0, 0), FVec2(tl.x, tl.y)))
    end
	
    -- Pos X
    if ( not dimension:IsSolidBlock(ax + 1, y, az) ) then
        model:AddVertex(Vertex(FVec3(ax + 1, y + 0, az + 1), FVec3(1, 0, 0), FVec2(br.x, br.y)))
        model:AddVertex(Vertex(FVec3(ax + 1, y + 0, az + 0), FVec3(1, 0, 0), FVec2(tl.x, br.y)))
        model:AddVertex(Vertex(FVec3(ax + 1, y + 1, az + 0), FVec3(1, 0, 0), FVec2(tl.x, tl.y)))
        
        model:AddVertex(Vertex(FVec3(ax + 1, y + 0, az + 1), FVec3(1, 0, 0), FVec2(br.x, br.y)))
        model:AddVertex(Vertex(FVec3(ax + 1, y + 1, az + 0), FVec3(1, 0, 0), FVec2(tl.x, tl.y)))
        model:AddVertex(Vertex(FVec3(ax + 1, y + 1, az + 1), FVec3(1, 0, 0), FVec2(br.x, tl.y)))
    end
    
    
    
    -- Pos-Z
    if ( not dimension:IsSolidBlock(ax, y, az + 1) ) then
        model:AddVertex(Vertex(FVec3(ax + 0, y + 0, az + 1), FVec3(0, 0, 1), FVec2(tl.x, br.y)))
        model:AddVertex(Vertex(FVec3(ax + 1, y + 0, az + 1), FVec3(0, 0, 1), FVec2(br.x, br.y)))
        model:AddVertex(Vertex(FVec3(ax + 0, y + 1, az + 1), FVec3(0, 0, 1), FVec2(tl.x, tl.y)))
        
        model:AddVertex(Vertex(FVec3(ax + 1, y + 0, az + 1), FVec3(0, 0, 1), FVec2(br.x, br.y)))
        model:AddVertex(Vertex(FVec3(ax + 1, y + 1, az + 1), FVec3(0, 0, 1), FVec2(br.x, tl.y)))
        model:AddVertex(Vertex(FVec3(ax + 0, y + 1, az + 1), FVec3(0, 0, 1), FVec2(tl.x, tl.y)))
    end
    
    
    -- Neg Z
    if ( not dimension:IsSolidBlock(ax, y, az - 1) ) then
        model:AddVertex(Vertex(FVec3(ax + 1, y + 0, az + 0), FVec3(0, 0, -1), FVec2(tl.x, br.y)))
        model:AddVertex(Vertex(FVec3(ax + 0, y + 0, az + 0), FVec3(0, 0, -1), FVec2(br.x, br.y)))
        model:AddVertex(Vertex(FVec3(ax + 1, y + 1, az + 0), FVec3(0, 0, -1), FVec2(tl.x, tl.y)))
        
        model:AddVertex(Vertex(FVec3(ax + 0, y + 0, az + 0), FVec3(0, 0, -1), FVec2(br.x, br.y)))
        model:AddVertex(Vertex(FVec3(ax + 0, y + 1, az + 0), FVec3(0, 0, -1), FVec2(br.x, tl.y)))
        model:AddVertex(Vertex(FVec3(ax + 1, y + 1, az + 0), FVec3(0, 0, -1), FVec2(tl.x, tl.y)))
    end
end





