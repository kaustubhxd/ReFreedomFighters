"""specs_s247.py - area 22, batch247 (src/batch247.cpp): ZFFSearchLightGroup::Save, CExplodeMolotov::Save. Streams are
helpers22._save_streams (A/B alternate on every return); 0x5c7830 and 0x4e74d0 are hooked; the light list is a Python
vtable (count, start, next) whose iterator is a stack local, so only its values are logged."""
from pilot import S
from helpers22 import _rnd, _hk, _pyvt, _save_streams

SLOTS = (0x3c, 0x44, 0x4c, 0x60, 0x64, 0x68, 0x6c, 0x70)


def _r(c):
    return c.rng.getrandbits(32)


def _g_5c7740(c):
    e = c.emu
    self_ = _rnd(c, 0x80)
    s = _save_streams(c, SLOTS)
    items = [_r(c) for _ in range(c.rng.choice([0, 1, 2, 4]))]
    cnt = _r(c)
    st = {'k': 0}

    def count(em, r):
        em.calllog.append(('list.14', 0x14, None, ()))
        em.ret(eax=cnt)

    def start(em, r):
        em.calllog.append(('list.4c', 0x4c, None, ()))
        st['k'] = 0
        em.w32(em.arg32(0), 0x55aa0000)
        em.ret(eax=0x13579bdf, argbytes=4)

    def nxt(em, r):
        k = st['k']
        em.calllog.append(('list.5c', 0x5c, None, (em.r32(em.arg32(0)),)))
        if k < len(items):
            em.w32(em.arg32(0), 0x55aa0001 + k)
            v = items[k]
        else:
            em.w32(em.arg32(0), 0)
            v = 0x77770000 + k
        st['k'] = k + 1
        em.ret(eax=v, argbytes=4)
    lst = _rnd(c, 0x20)
    e.w32(lst, _pyvt(c, {0x14: count, 0x4c: start, 0x5c: nxt}))
    e.w32(self_ + 0x60, lst)
    _hk(c, 0x5c7830, '5c7830', 2)
    e.mu.ctl_flush_tb()
    return [self_, s]


def _g_584d20(c):
    self_ = _rnd(c, 0x380)
    s = _save_streams(c, SLOTS)
    _hk(c, 0x4e74d0, '4e74d0', 1)
    c.emu.mu.ctl_flush_tb()
    return [self_, s]


S(0x5c7740, 'ZFFSearchLightGroup::Save', 'thiscall', None, ret='al', gen=_g_5c7740,
  note='batch247; light list count/start/next, 0x5c7830 hooked')
S(0x584d20, 'CExplodeMolotov::Save', 'thiscall', None, ret='al', gen=_g_584d20,
  note='batch247; five particle groups, 0x4e74d0 hooked, chained returns')
