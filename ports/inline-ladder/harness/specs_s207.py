"""specs_s207.py - ladder thread batches 207 and 208: hero action slots 0x3d8 (RunLnkAction) and 0x3ec (CreateLnkAction)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import ladder_kit as K

ASSERT_HOOK = 0x7003b0


def _run(c):
    e, r = c.emu, c.rng
    self_ = K.rnd(c, 0x200)
    ctl = K.rnd(c, 0x20)
    e.w32(ctl + 4, 0 if r.random() < 0.7 else r.getrandbits(32) | 1)
    ret = r.getrandbits(32)
    e.w32(ctl, K.vt(c, 'runner', {4: (1, lambda e2, a: (ret, None, None))}, nslots=8))
    e.w32(self_ + 0x1ce, ctl)
    if r.random() < 0.6:
        def h(e2, res):
            e2.calllog.append(('assert-hook',))
            e2.ret()
        e.w32(ASSERT_HOOK, e.stub_fn('assert hook', h))
    return [self_, r.getrandbits(32)]


S(0x467740, 'ZIKLNKOBJ::RunLnkAction', 'thiscall', None, ret='eax', gen=_run,
  note='batch207; assert runner idle, then runner slot 4 (action)')


def _create(c):
    e, r = c.emu, c.rng
    hero = K.rnd(c, 0x800)
    hand = r.getrandbits(32)
    e.w32(hero, K.vt(c, 'hero', {0x4f8: (0, lambda e2, a: (hand, None, None))}, nslots=0x150))

    def new(e2, res):
        n = e2.arg32(0)
        p = 0 if r.random() < 0.08 else K.rnd(c, max(n, 4))
        e2.calllog.append(('new', n, p))
        e2.ret(eax=p)
    e.hook(0x41e290, new)

    def base(e2, res):
        e2.calllog.append(('ZLNKWHANDS::CreateLnkAction', e2.reg('ecx'), e2.arg32(0)))
        e2.ret(eax=0x5eed0000 | (e2.arg32(0) & 0xffff), argbytes=4)
    e.hook(0x4733d0, base)
    k = r.random()
    if k < 0.75:
        i = r.choice([4] + list(range(0x11, 0x1e)))
    elif k < 0.9:
        i = r.randint(0, 0x20)
    else:
        i = r.getrandbits(32)
    return [hero, i]


S(0x590820, 'ZFFHERO::CreateLnkAction', 'thiscall', None, ret='eax', gen=_create,
  note='batch208; switch on action id, new + RTTI-named constructor, default ZLNKWHANDS::CreateLnkAction')
