"""specs_s34021.py - cascade tier E, batch 34021.
0x60efb0: the import EnumDisplaySettingsA is a Python stub (logs its three arguments and dmSize, fills the DEVMODE except dmSize with random bytes, returns 1, pops 12);
engine +0x923 holds a pointer to a string that is empty in a third of the cases; 0x6519a0 hooked; this slot 0x268 a recorder; the /GS check 0x633654 a zero-argument recorder.
0x494ac0: engine slot 0x1c8 returns a random 64-bit value (EDX set through the register), slot 0x190 an object whose slot 0x184 records ECX (its vtable) and six stack args.
0x4a8460: engine table slot 0x138 returns an object whose slot 0x88 writes a random dword through its (stack) pointer argument; table slot 0x114 returns random words.
0x4b10c0: the dword at +0x52 is zero in half the cases; the string pointer at +0x56 is empty in a third of those; slots 0x94 / 0x90 return an entry (0 in a fifth)."""
from unicorn.x86_const import UC_X86_REG_EDX
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec, sysobj


def _g60efb0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def enum_disp(em, res_):
        buf = em.arg32(2)
        em.calllog.append(('EnumDisplaySettingsA', em.arg32(0), em.arg32(1), em.r32(buf + 0x24)))
        for off in range(0, 0x9c, 4):
            if off != 0x24:
                em.w32(buf + off, r.getrandbits(32))
        em.ret(eax=1, argbytes=12)
    e.stub_import('EnumDisplaySettingsA', enum_disp)
    hook_rec(c, 0x6519a0, 1, this=True)
    hook_rec(c, 0x633654, 0, pop=0)
    so = sysobj(c)
    sbuf = rnd(c, 0x10)
    if r.random() < 0.33:
        e.wbytes(sbuf, b'\0')
    else:
        e.wbytes(sbuf, bytes([r.randrange(1, 256)]))
    e.wbytes(so + 0x923, sbuf.to_bytes(4, 'little'))
    me = obj(c, 0x200, {0x268: pystub(c, 0, this=True)}, nslots=0x280)
    return [me, r.getrandbits(32)]


def _g494ac0(c):
    clear_hooks(c)
    r = c.rng

    def set_edx(em, k):
        em.mu.reg_write(UC_X86_REG_EDX, r.getrandbits(32))
    o = obj(c, 0x20, {0x184: pystub(c, 6, this=True, pop=0)}, nslots=0x1a0)
    sysobj(c, slots={0x1c8: pystub(c, 2, ret=lambda em, k: r.getrandbits(32), this=True, side=set_edx),
                     0x190: pystub(c, 0, ret=o, this=True)})
    me = rnd(c, 0x20)
    c.emu.w32(me + 4, r.choice([0, 1, 2, 3, 5, r.getrandbits(32)]))
    return [me, r.getrandbits(32)]


def _g4a8460(c):
    clear_hooks(c)
    r = c.rng

    def wtmp(em, k):
        em.w32(em.arg32(1), r.getrandbits(32))
    t = obj(c, 0x20, {0x88: pystub(c, 2, this=True, side=wtmp, stackmark=(1,))}, nslots=0x30)
    sysobj(c, table_slots={0x138: pystub(c, 0, ret=t, this=True),
                           0x114: pystub(c, 4, ret=lambda em, k: r.getrandbits(32), this=True)}, table_size=0x200)
    return [rnd(c, 0x60)]


def _g4b10c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    ent = lambda: 0 if r.random() < 0.2 else rnd(c, 0x60)
    sink = obj(c, 0x20, {0x130: pystub(c, 3, this=True)}, nslots=0x40)
    me = obj(c, 0x100, {0x94: pystub(c, 2, ret=ent(), this=True), 0x90: pystub(c, 3, ret=ent(), this=True)}, nslots=0x40)
    e.w32(me + 0x44, sink)
    k = 0 if r.random() < 0.5 else (r.getrandbits(32) | 1)
    e.wbytes(me + 0x52, k.to_bytes(4, 'little'))
    sbuf = rnd(c, 0x10)
    e.wbytes(sbuf, b'\0' if r.random() < 0.33 else bytes([r.randrange(1, 256)]))
    e.wbytes(me + 0x56, sbuf.to_bytes(4, 'little'))
    return [me, r.getrandbits(32), r.getrandbits(32)]


S(0x60efb0, 'GUESS store mode, read display frequency', 'thiscall', None, ret=None, gen=_g60efb0, note='batch34021')
S(0x494ac0, 'GUESS timer-delta layout row', 'thiscall', None, ret=None, gen=_g494ac0, note='batch34021')
S(0x4a8460, 'GUESS read four settings', 'thiscall', None, ret=None, gen=_g4a8460, note='batch34021')
S(0x4b10c0, 'GUESS resolve entry by id or name, push numbers', 'thiscall', None, ret=None, gen=_g4b10c0, note='batch34021')
