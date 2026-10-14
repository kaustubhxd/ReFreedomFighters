"""specs_s35113.py - 0x578c70 (thiscall, no args). this: object (0x200 random bytes) with vtable slot 0xd0 (1 arg), index dword at +0x194 and option bytes at +0x1b4 .. +0x1b7; 0x579bd0, 0x579b20, 0x579a60 hooked (thiscall, 1 arg each); engine slot 0x190 returns s (slot 0x198: cdecl-style four
stack args, ECX = vtable, fills the 0x40-byte buffer); engine table slot 0x134 returns t whose slot 0x68 is a custom stub logging the buffer content and only the low byte of its second argument (the exe pushes an uninitialised dword)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, sysobj


def _g578c70(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    for a in (0x579bd0, 0x579b20, 0x579a60):
        hook_rec(c, a, 1, this=True)
    data = bytes(r.getrandbits(8) for _ in range(0x40))

    def fill(em, k):
        em.wbytes(em.arg32(1), data)
    s = obj(c, 0x20, {0x198: pystub(c, 4, nullflag=(1,), this=True, pop=0, side=fill)}, nslots=0x67)

    def l68(em, rr):
        em.calllog.append(('slot68', em.reg('ecx'), bytes(em.rbytes(em.arg32(0), 0x40)), em.arg32(1) & 0xff, em.arg32(2)))
        em.ret(eax=0, argbytes=12)
    t = obj(c, 0x20, {0x68: e.stub_fn('slot68', l68)}, nslots=0x1c)
    sysobj(c, slots={0x190: pystub(c, 0, ret=s, this=True)}, table_slots={0x134: pystub(c, 0, ret=t, this=True)}, table_size=0x140)
    me = obj(c, 0x200, {0xd0: pystub(c, 1, this=True)}, nslots=0x35)
    e.w32(me + 0x194, r.randint(0, 3))
    return [me]


S(0x578c70, 'GUESS apply option bytes and show label', 'thiscall', None, ret=None, gen=_g578c70, note='batch35113')
