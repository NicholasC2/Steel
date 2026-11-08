const std = @import("std");
const nds = @import("nds");

export fn main(_: c_int, _: [*]const [*:0]const u8) void {
    while (true) {
        nds.swiWaitForVBlank();
    }
}
