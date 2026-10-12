"""specs_s246.py - area 22, batch246 (src/batch246.cpp): CFireController::Load, CRigidBody::Load. The load stream is
helpers22._loader (per-case byte stream, slot widths GUESS); 0x6352f0 writes a per-case handle through its pointer;
0x546040 is hooked; this->vt[4] logs the name it is given (read through the pointer)."""
from pilot import S
from helpers22 import _rnd, _hk, _pyvt, _loader


def _r(c):
    return c.rng.getrandbits(32)


def _g_5848a0(c):
    e = c.emu
    self_ = _rnd(c, 0x400)
    e.w32(self_ + 0x4c, c.rng.randint(0, 3))
    handle = c.rng.choice([0, _r(c)])

    def name_out(em, r, v=handle):
        em.calllog.append(('6352f0', 0, em.reg('ecx'), ()))
        em.w32(em.arg32(0), v)
        em.ret(eax=0, argbytes=4)
    e.hook(0x6352f0, name_out)

    def slot4(em, r):
        em.calllog.append(('self.4', 4, em.reg('ecx'), (em.r32(em.arg32(0)),)))
        em.ret(eax=0, argbytes=4)
    e.w32(self_, _pyvt(c, {4: slot4}))
    n = c.rng.choice([0, 1, 2, 3, 5])
    l = _loader(c, {0x50: 4, 0x6c: 12}, log_ptr=False,
                extra={0x40: _count_then_words(n)})
    e.mu.ctl_flush_tb()
    return [self_, l]


def _count_then_words(n):
    st = {'k': 0}

    def h(em, r):
        em.calllog.append(('load', 0x40, None, (st['k'],)))
        em.w32(em.arg32(0), n if st['k'] == 0 else (0x1000 + 0x111 * st['k']) & 0xffffffff)
        st['k'] += 1
        em.ret(eax=0, argbytes=4)
    return h


def _g_53fc40(c):
    e = c.emu
    self_ = _rnd(c, 0x180)
    e.w32(self_ + 0xcf, _rnd(c, 0x40))
    _hk(c, 0x546040, '546040', 1)
    l = _loader(c, {0x74: 0x24, 0x48: 4, 0x50: 4, 0x6c: 12, 0x68: 1, 0x40: 4, 0x58: 4})
    e.mu.ctl_flush_tb()
    return [self_, l]


S(0x5848a0, 'CFireController::Load', 'thiscall', None, ret='al', gen=_g_5848a0,
  note='batch246; cookie not reproduced; record loop of 7 dwords at +0x50')
S(0x53fc40, 'CRigidBody::Load', 'thiscall', None, ret='al', gen=_g_53fc40,
  note='batch246; 0x546040 hooked; 12 field reads')
