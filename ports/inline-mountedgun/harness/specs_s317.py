"""specs_s317.py - mounted gun batch 317: ZTankIf::DriveToSplineVal wrapper. ZTank::DriveToSplineVal (0x520c50) is
hooked; both sides log its this, float and bool arguments."""
from pilot import S
from mg_helpers import _rnd, flush, make_block


def _gen(c):
    r = c.rng

    def h(e, rr):
        e.calllog.append(('DriveToSplineVal', e.reg('ecx'), e.arg32(0), e.arg32(1)))
        e.ret(argbytes=8)
    c.emu.hook(0x520c50, h)
    s = _rnd(c, 0x40)
    tank = _rnd(c, 0x40)
    c.emu.w32(s + 0x1c, tank)
    fv = c.fv()
    # value array: 4 entries of {dword, type byte}; entry 0 float, entry 1 flag dword
    data = c.emu.alloc(8 * 4, 4)
    for i in range(4):
        c.emu.w32(data + 8 * i, c.rng.getrandbits(32))
        c.emu.w8(data + 8 * i + 4, 0)
    c.emu.wf32(data, fv)
    c.emu.w32(data + 8, r.choice([0, 1, r.getrandbits(32)]))
    arr = _rnd(c, 0x10)           # array struct: +0 values, +8 size
    c.emu.w32(arr, data)
    c.emu.w32(arr + 8, 4)
    arrobj = _rnd(c, 0x10)        # block: +0 array, +4 first index, +8 count
    c.emu.w32(arrobj, arr)
    c.emu.w32(arrobj + 4, 0)
    c.emu.w32(arrobj + 8, 4)
    par = _rnd(c, 0x10)
    c.emu.w32(par + 4, arrobj)
    flush(c)
    return [s, par]


S(0x522770, 'ZTankIf::DriveToSplineVal', 'thiscall', None, gen=_gen, note='batch317; callee hooked')
