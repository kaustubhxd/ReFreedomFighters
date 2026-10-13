"""specs_s1008.py - unclaimed-02 batch 8 (docs/20-unclaimed-02.md): ZRunParamAnim::Key (0x4e6ed0). The sub-object at this+0xc
is a logging fake vtable: slot +0x4c resets a cursor, slot +0x5c writes the flag through its pointer and returns the next
item from a random list (key at +4, value at +0x18). Keys are drawn from the items and one extra so both branches run."""
from pilot import S


def _rnd(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _key(c):
    self_ = _rnd(c, 0x100)
    n = c.rng.randint(0, 4)
    items = []
    for _ in range(n):
        it = _rnd(c, 0x40)
        c.emu.w32(it + 4, c.rng.choice([1, 2, 3, c.rng.getrandbits(32)]))
        c.emu.w32(it + 0x18, c.rng.getrandbits(32))
        items.append(it)
    st = {'i': 0}

    def h4c(e, r):
        st['i'] = 0
        e.calllog.append(('ZRunParamAnim::sub+4c',))
        e.ret(eax=0, argbytes=4)

    def h5c(e, r):
        out = e.arg32(0)
        if st['i'] < len(items):
            it = items[st['i']]
            st['i'] += 1
            e.w32(out, 1)
            e.calllog.append(('ZRunParamAnim::sub+5c', 1))
            e.ret(eax=it, argbytes=4)
        else:
            e.w32(out, 0)
            e.calllog.append(('ZRunParamAnim::sub+5c', 0))
            e.ret(eax=0, argbytes=4)

    vt = c.emu.fake_vtable('ZRunParamAnim-sub', 0x60, {0x4c: h4c, 0x5c: h5c})
    c.emu.w32(self_ + 0xc, vt)
    return [self_, c.rng.choice([1, 2, 3, c.rng.getrandbits(32)]), c.emu.alloc(4, 4)]


S(0x4e6ed0, 'ZRunParamAnim::Key(int, float&) thiscall', 'thiscall', None, ret='al', gen=_key,
  note='unclaimed-02 batch 8; walks sub-object at +0xc via vslots +0x4c and +0x5c, matches key at +4, stores +0x18')
