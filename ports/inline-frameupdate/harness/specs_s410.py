"""specs_s410.py - batch 410: ZCollisionBox::GetStrips (low confidence name)."""
from pilot import S
import fu_kit as K


def _strips(c):
    r = c.rng
    e = c.emu
    K.hooks(c, {})
    box_sys = K.obj(c, 0x40, {0x84: K.fn(c, 'boxsys.fillStrips', 8, ret=K.bool8(c, 0.7))}, 'boxsys')
    hold = K.rnd(c, 0x20)
    e.w32(hold + 0x1c, box_sys)
    sysobj = K.rnd(c, 0x1b00)
    e.w32(sysobj + 0x1aa3, hold)
    e.w32(0x70039c, sysobj)
    log_print = K.fn(c, 'log.print', 3, cdecl=True, noecx=True)
    log = K.obj(c, 0x40, {0x2c: log_print}, 'log')
    logger = K.obj(c, 0x40, {0x20: K.fn(c, 'logger.at', 2, ret=log)}, 'logger')
    e.w32(0x700390, logger)
    self = K.rnd(c, 0x60)
    e.w32(self + 0xc, r.choice([0, 1, 16, 64, 0xffffffff]))
    e.w32(self + 0x10, r.choice([0, 8, 16, 64, 100]))
    e.w32(self + 0x14, r.getrandbits(32))
    mask = r.choice([0, 1, 2, 0x20, r.getrandbits(32)])
    return [self, mask]


S(0x4ea300, 'ZCollisionBox::GetStrips (low)', 'thiscall', None, ret='al', gen=_strips,
  note='batch410; name low confidence; box fill as stub')
