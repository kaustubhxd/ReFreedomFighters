"""specs_s34019.py - cascade tier E, batch 34019. 0x5f9450 (a has slot 0x2c as a recorder; c = {array, ?, count} with count 0..6; hooked 0x605a10 records ECX and its three
stack args); 0x604460 (hooked 0x5fb550 returns 0/1, assert hook always set; table of 16 handlers, each null or an object whose slot 0 returns 0 or a value; low word of b below 16,
high word random; hooked 0x5f4600 / 0x5f4ac0 record a and the value)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _g5f9450(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x605a10, 3, this=True)
    a = obj(c, 0x20, {0x2c: pystub(c, 1, this=True)}, nslots=0x30)
    cc = rnd(c, 0x10)
    c.emu.w32(cc, rnd(c, 0x40))
    c.emu.w32(cc + 8, r.choice([0, 1, 2, 3, 6, r.randint(0, 6)]))
    return [rnd(c, 0x20), a, r.getrandbits(32), cc]


def _assert_hook(c):
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))


def _g604460(c):
    clear_hooks(c)
    r = c.rng
    _assert_hook(c)
    hook_rec(c, 0x5fb550, 1, ret=r.choice([0, 1, 1]) | (r.getrandbits(24) << 8), this=True)
    hook_rec(c, 0x5f4600, 1, this=True)
    hook_rec(c, 0x5f4ac0, 0, this=True, pop=0)
    tab = rnd(c, 4 * 0x110)
    for i in list(range(16)) + list(range(0x100, 0x110)):
        h = 0 if r.random() < 0.3 else obj(c, 0x20, {0: pystub(c, 3, ret=r.choice([0, r.getrandbits(32) | 1]), this=True)}, nslots=4)
        c.emu.w32(tab + 4 * i, h)
    me = rnd(c, 0x20)
    c.emu.w32(me + 8, tab)
    b = (r.getrandbits(16) << 16) | r.choice([0, 0x100]) + r.randrange(16)
    return [me, rnd(c, 0x20), b, r.getrandbits(32)]


S(0x5f9450, 'GUESS apply helper to each entry', 'thiscall', None, ret=None, gen=_g5f9450, note='batch34019')
S(0x604460, 'GUESS dispatch record id through handler table', 'thiscall', None, ret=None, gen=_g604460, note='batch34019')
