"""specs_s66040.py - cascade s4 batch 66040: 0x622540 (decode a UTF-16BE XML entity name)."""
from pilot import S
from recruits_util import clear_hooks


def _g622540(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    names = [b'lt', b'gt', b'amp', b'quot', b'apos', b'xx', b'a', b'amps', b'quo', b'qu']
    nm = r.choice(names)
    raw = b''.join(b'\0' + bytes([ch]) for ch in nm)
    raw = bytearray(raw)
    if r.random() < 0.4 and raw:
        raw[r.randrange(len(raw))] = r.choice([0, 1, 0x41, 0x6c, 0x74])
    cut = r.choice([0, 0, 0, 1, -1])
    ln = max(len(raw) + cut, 0)
    buf = e.alloc(0x20, 8)
    e.wbytes(buf, bytes(raw) + bytes(r.randrange(1, 255) for _ in range(0x10)))
    return [r.getrandbits(32), buf, buf + ln]


S(0x622540, 'GUESS decode a UTF-16BE XML entity name', 'cdecl', None, ret='eax', gen=_g622540, note='batch66040')
