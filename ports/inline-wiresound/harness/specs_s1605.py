"""specs_s1605.py - soundtimers batch 1605: ZFFHERO::PlaySound_Command and ZIKLNKOBJ::Sound_GetTimeLeft.
The hero is a ZIKLNKOBJ world (sthelp.world) with the hero line table at +0xef2."""
from pilot import S
from sthelp import Seq, world, except1


def _timeleft(c):
    seq = Seq(c)
    me, hc, hn = world(c, seq)
    return [me]


S(0x467ca0, 'ZIKLNKOBJ::Sound_GetTimeLeft', 'thiscall', None, ret='st0', gen=_timeleft,
  note='batch1605; x87 float return of the current speech +0x70 or 0.0')


def _command(c):
    seq = Seq(c)
    r = c.rng
    except1(c)
    me, hc, hn = world(c, seq, size=0x1000)
    c.emu.w8(me + 0x13a, r.choice([0, 1, 1, 1, 1]))
    for i in range(24):
        c.emu.w32(me + 0xef2 + 4 * i, 0 if r.random() < 0.25 else r.getrandbits(32))
    line = r.choice([0xb, 0xd, 0xf, 0x11, 0x13, 0x15]) if r.random() < 0.8 else r.randint(0, 22)
    if r.random() < 0.3:   # the same line is the current speech
        c.emu.w32(me + 0x13f, c.emu.r32(me + 0xef2 + 4 * line))
    c.emu.w32(me + 0xf5e, r.choice([0, 25, -25, r.getrandbits(32)]))
    return [me, line, r.choice([0, 1, 0x100, r.getrandbits(32)])]


S(0x594040, 'ZFFHERO::PlaySound_Command', 'thiscall', None, ret='eax', gen=_command,
  note='batch1605; order line (+ "All" line), returns the spoken length in ms')
