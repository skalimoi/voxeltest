 
#ifndef WATER_GENERATOR_H
#define WATER_GENERATOR_H

#include <godot_cpp/classes/voxel_generator_script.hpp>
#include <godot_cpp/classes/voxel_buffer.hpp>
#include <godot_cpp/classes/voxel_terrain.hpp>
#include <godot_cpp/classes/voxel_tool.hpp>

namespace godot {

class WaterGenerator : public VoxelGeneratorScript {
	GDCLASS(WaterGenerator, VoxelGeneratorScript)

private:

	Ref<VoxelTool> terrain_tool;
	int channel;
	int channel_mask;


protected:
	static void _bind_methods();

public:
	WaterGenerator();
	~WaterGenerator();

	void m_create(VoxelTerrain* terrain);

	void _generate_block(const Ref<VoxelBuffer> &out_buffer, const Vector3i &origin_in_voxels, int lod) override;
	int _get_used_channels_mask() const override;
};

}

#endif
