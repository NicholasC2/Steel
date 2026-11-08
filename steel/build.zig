const std = @import("std");
const anne_nds = @import("anne_nds_dev");

pub fn build(b: *std.Build) void {
    const optimize = b.standardOptimizeOption(.{});

    const steel_mod = b.createModule(.{
        .root_source_file = b.path("src/main.zig"),
        .target = anne_nds.ndsTarget(b),
        .optimize = optimize,
        .link_libc = true,
    });

    steel_mod.addImport("nds", b.dependency("anne_nds_dev", .{}).module("anne_nds_dev"));

    const nds = anne_nds.compileNds(b, .{
        .name = "steel",
        .module = steel_mod,
    });

    b.default_step.dependOn(&nds.step);
}
