"""specs_c117.py - climb thread batch 117: ZPlayer::CalcAnimRemapNames (0x481530)."""
import struct
from pilot import S
from ckit import obj, rnd


def _cal(c):
    r = c.rng
    e = c.emu
    self_ = rnd(c, 0x1000)
    n = r.choice([0, 1, 2, 3, 5])
    e.w32(self_ + 0x459, n)
    # the exe walks slots +0x45d+4*n down to +0x45d+4 (index 0 is never used), so fill indices 0..n+1 (0 = unused)
    for i in range(0, n + 2):
        if i == 0 or r.random() < 0.2:
            e.w32(self_ + 0x45d + 4 * i, 0)
            continue
        tag = 'item%d' % i
        o = obj(e, tag, 0x20, {0x20: (0, lambda e, t, a, tag=tag: (0, None, (tag,)))})
        e.w32(self_ + 0x45d + 4 * i, o)

    def hands(e, res):
        e.calllog.append(('ZLNKWHANDS::CalcAnimRemapNames', e.reg('ecx')))
        e.ret()
    e.hook(0x472460, hands)
    return [self_]


S(0x481530, 'ZPlayer::CalcAnimRemapNames', 'thiscall', None, ret=None, gen=_cal,
  note='c117; ZLNKWHANDS::CalcAnimRemapNames is a hook (its 1075 bytes are not lifted yet)')
