"""specs_s213063.py - batch 213063: case setup with stack record, IAT atoi and /GS check, Sonnet-w3b."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g5732a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    a = r.choice([2, 3, 4, 5, 6, 7, 8, 9, 10] * 3 + [0, 1, 11, 12, 0xffffffff, r.getrandbits(32)])

    def vsl(n, ret=None, **kw):
        return pystub(c, n, ret=(r.getrandbits(32) if ret is None else ret), this=True, **kw)
    x1 = obj(c, 0x20, {0x64: vsl(2), 0x68: vsl(3)}, nslots=0x40)
    tab = obj(c, 0x20, {0x134: vsl(0, x1)}, nslots=0x80)
    # 0x68 is also called on the table's object; x1 plays both roles
    def slot5c_side(emu, k):
        emu.w32(emu.arg32(1), r.choice([0, 3, 5, 11, 12, 100, r.getrandbits(32)]))
    eng = obj(c, 0x1b00, {0x5c: vsl(2, lambda emu, k: r.choice([0, 1, 0x100, 0x1ff, r.getrandbits(32)]), nullflag=(1,), side=slot5c_side),
                          0xbc: vsl(0, x1)}, nslots=0x60)
    e.w32(eng + 0x9b, tab)
    e.w32(0x70039c, eng)
    e.w32(0x6762d8, pystub(c, 1, ret=lambda emu, k: r.choice([0, 3, 5, 6, 10, 11, 12, 100, r.getrandbits(32)]), pop=0))
    m = obj(c, 0x20, {0x2c: pystub(c, 2, ret=r.getrandbits(32), this=True, pop=0)}, nslots=0x14)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=m, this=True)}, nslots=0x10)
    e.w32(0x700390, lg)
    this = rnd(c, 0x200)
    e.w32(this + 0x94, rnd(c, 0x440))
    e.wbytes(this + 0x180, bytes([r.choice([0, 1, 1, 0xff])]))
    for ad, n, rv in ((0x562c20, 1, lambda emu, k: r.choice([0, 0, 0, 1, 0x100, r.getrandbits(32)])), (0x562b50, 1, None),
                      (0x561be0, 0, lambda emu, k: r.choice([0, 1, 1, 0x100, r.getrandbits(32)])), (0x561f10, 1, None),
                      (0x563500, 0, None), (0x59ca50, 1, None), (0x5ae710, 1, None)):
        hook_rec(c, ad, n, ret=(r.getrandbits(32) if rv is None else rv), this=True)

    def ctor_side(emu, k):
        emu.wbytes(emu.reg('ecx'), bytes(r.getrandbits(8) for _ in range(0x3c0)))
    hook_rec(c, 0x5ad790, 0, ret=r.getrandbits(32), this='mark', side=ctor_side)
    hook_rec(c, 0x56e9d0, 1, ret=r.getrandbits(32), this=True, deref={0: -0x3c0})
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    return [this, a]


S(0x5732a0, 'command_state_setup', 'thiscall', None, ret='al', gen=g5732a0)
