"""specs_c1037.py - camera batch 1037: ZShakeCamera Save and Load. DBREAD readers and GetInput are hooked with
random results (the same results in both builds); the load object writes random handles."""
import struct
from pilot import S
from camgen import rnd, fbits, f32, Log, handler, sys_with_mgr


def _save(c):
    r = c.rng
    log = Log(c, 256)
    sg = c.emu.fake_object('sg', 0x10, slots={0x64: handler(log, 0x64, 1)})
    o = rnd(c, 0x70)
    c.emu.w32(o + 4, r.getrandbits(32))
    for off in (0x55, 0x59, 0x5d, 0x61):
        c.emu.w32(o + off, r.getrandbits(32))
    return [o, sg]


S(0x5d3740, 'ZShakeCamera::Save', 'thiscall', ret='al', gen=_save)


def _load(c):
    r = c.rng
    log = Log(c, 256)
    # The hooks log only their tags: ECX and the argument are stack addresses, which differ between the builds.
    def tag_only(addr, eax=None, st0=None, nargs=0):
        def h(e, res):
            log.put(addr)
            if st0 is not None:
                e.ret(st0=st0(), argbytes=4 * nargs)
            else:
                e.ret(eax=eax(), argbytes=4 * nargs)
        return h
    c.emu.hook(0x6352f0, tag_only(0x6352f0, eax=lambda: 0, nargs=1))
    c.emu.hook(0x4e5e80, tag_only(0x4e5e80, st0=lambda: f32(c)))
    c.emu.hook(0x4e5e40, tag_only(0x4e5e40, eax=lambda: r.getrandbits(16)))
    c.emu.hook(0x4e5e60, tag_only(0x4e5e60, eax=lambda: r.choice([0, 1, r.getrandbits(32)])))

    def lg40(e, res):  # load object slot 0x40(u32* out): a handle
        e.w32(e.arg32(0), r.getrandbits(32))
        e.ret(argbytes=4)
    lg = c.emu.fake_object('lg', 0x10, slots={0x40: lg40})
    s = sys_with_mgr(c, 0x100)
    m = c.emu.fake_object('mgr', 0x140, slots={0x58: handler(log, 0x58, 1, eax=lambda e: r.getrandbits(32))})
    c.emu.w32(s + 0x9b, m)
    o = rnd(c, 0x70)
    return [o, lg]


S(0x5d3660, 'ZShakeCamera::Load', 'thiscall', ret='al', gen=_load)
