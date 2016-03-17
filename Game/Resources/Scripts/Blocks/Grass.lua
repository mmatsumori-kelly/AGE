



function IsSolid(block)
	return true
end


-- Load stuff for the block
function AddVertexData(block, model)
	local chunk = block:GetChunk()
	local dimension = chunk:GetDimension()
	
	local x = block:GetX()
	local y = block:GetY()
	local z = block:GetZ()
	local ax = chunk:GetX() * ChunkWidth  + x
	local az = chunk:GetZ() * ChunkLength + z
	
	
	local tx = 0
	local ty = 0
	local tl = BlockTexture.GetTexCoord(tx + 0.05, ty + 0.05)
	local br = BlockTexture.GetTexCoord(tx + 0.95, ty + 0.95)
	
	
	
	-- Pos Y
	if ( not chunk:IsSolidBlock(x, y + 1, z) ) then
		model:AddVertex(Vertex(FVec3(ax + 0, y + 1, az + 0), FVec3(0, 1, 0), FVec2(br.x, br.y)))
		model:AddVertex(Vertex(FVec3(ax + 0, y + 1, az + 1), FVec3(0, 1, 0), FVec2(br.x, tl.y)))
		model:AddVertex(Vertex(FVec3(ax + 1, y + 1, az + 1), FVec3(0, 1, 0), FVec2(tl.x, tl.y)))
		
		model:AddVertex(Vertex(FVec3(ax + 0, y + 1, az + 0), FVec3(0, 1, 0), FVec2(br.x, br.y)))
		model:AddVertex(Vertex(FVec3(ax + 1, y + 1, az + 1), FVec3(0, 1, 0), FVec2(tl.x, tl.y)))
		model:AddVertex(Vertex(FVec3(ax + 1, y + 1, az + 0), FVec3(0, 1, 0), FVec2(tl.x, br.y)))
	end
	
	-- Neg Y
	if ( not chunk:IsSolidBlock(x, y - 1, z) ) then
		model:AddVertex(Vertex(FVec3(ax + 0, y + 0, az + 1), FVec3(0, -1, 0), FVec2(tl.x, br.y)))
		model:AddVertex(Vertex(FVec3(ax + 0, y + 0, az + 0), FVec3(0, -1, 0), FVec2(br.x, br.y)))
		model:AddVertex(Vertex(FVec3(ax + 1, y + 0, az + 0), FVec3(0, -1, 0), FVec2(br.x, tl.y)))
		
		model:AddVertex(Vertex(FVec3(ax + 0, y + 0, az + 1), FVec3(0, -1, 0), FVec2(tl.x, br.y)))
		model:AddVertex(Vertex(FVec3(ax + 1, y + 0, az + 0), FVec3(0, -1, 0), FVec2(br.x, tl.y)))
		model:AddVertex(Vertex(FVec3(ax + 1, y + 0, az + 1), FVec3(0, -1, 0), FVec2(tl.x, tl.y)))
	end
	
	
	local tx = 1
	local ty = 0
	local tl = BlockTexture.GetTexCoord(tx + 0.05, ty + 0.05)
	local br = BlockTexture.GetTexCoord(tx + 0.95, ty + 0.95)
	
	
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





